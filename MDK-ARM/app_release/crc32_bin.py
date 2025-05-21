import os
import zlib
import shutil

def main():
    # 定义文件路径（与原批处理脚本路径一致）
    original_bin = r"C:\Users\crs\Desktop\SerialDebug\SerialDebug\MDK-ARM\app_release\app.bin"
    copied_bin = r"C:\Users\crs\Desktop\SerialDebug\SerialDebug\MDK-ARM\app_release\app_with_crc.bin"

    # 步骤 1：检查原始文件是否存在
    if not os.path.exists(original_bin):
        print(f"[错误] 文件 {original_bin} 不存在，脚本终止执行。")
        return

    print(f"[信息] 已检测到原始文件：{original_bin}")

    # 步骤 2：复制原始文件
    try:
        print(f"[操作] 正在复制原始文件到 {copied_bin}...")
        shutil.copyfile(original_bin, copied_bin)
        print(f"[成功] 原始文件已成功复制到 {copied_bin}")
    except Exception as e:
        print(f"[错误] 文件复制失败，错误信息：{str(e)}")
        return

    # 步骤 3：计算原始文件的 CRC32 校验值
    try:
        print("[操作] 正在计算原始文件的 CRC32 校验值...")
        with open(original_bin, "rb") as f:
            data = f.read()
            crc32_raw = zlib.crc32(data)  # 返回有符号整数
            crc32_hex = format(crc32_raw & 0xFFFFFFFF, "08x")  # 转换为 8 位无符号十六进制（小写）
        print(f"[信息] 原始文件 CRC32 校验值（十六进制）：{crc32_hex}")
    except Exception as e:
        print(f"[错误] CRC32 计算失败，错误信息：{str(e)}")
        return

    # 步骤 4：将 CRC32 校验值追加到复制后的文件
    try:
        print(f"[操作] 正在将 CRC32 校验值（{crc32_hex}）追加到 {copied_bin}...")
        crc_bytes = crc32_raw.to_bytes(4, byteorder="little")  # 转换为 4 字节（小端序，与原批处理逻辑一致）
        with open(copied_bin, "ab") as f:
            f.write(crc_bytes)
        print(f"[完成] CRC32 校验值已成功追加到 {copied_bin} 文件末尾。")
    except Exception as e:
        print(f"[错误] 校验值追加失败，错误信息：{str(e)}")
        return

if __name__ == "__main__":
    main()