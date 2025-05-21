#include "app_define.h"

#include "adc.h"



#define  OUTLINE_W    50 //���ͼ����
#define  OUTLINE_H    25 //���ͼ��߶�

#define BATTERY_VOLT_MIN 3.3F   // 0% ��Ӧ��ѹ
#define BATTERY_VOLT_MAX 4.2F   // 100% ��Ӧ��ѹ

// ��ص����ٷֱ�ת��
uint8_t battery_get_percentage(float volt)
{
    if (volt <= BATTERY_VOLT_MIN) return 0;
    if (volt >= BATTERY_VOLT_MAX) return 100;

    return (uint8_t)((volt - BATTERY_VOLT_MIN) / (BATTERY_VOLT_MAX - BATTERY_VOLT_MIN) * 100);
}


uint32_t battery_get_adc_value(void)
{
	uint32_t adc_value;
	HAL_ADC_Start(&hadc2);
	HAL_ADC_PollForConversion(&hadc2, 10);   //�ȴ�ת����ɣ�50Ϊ���ȴ�ʱ�䣬��λΪms

	adc_value = HAL_ADC_GetValue(&hadc2);   //��ȡADֵ
	
	HAL_ADC_Stop(&hadc2);
	return adc_value;
}

float battery_get_volt(uint32_t adc_value)
{
	float volt = battery_get_adc_value() / 4096.0F *3.3F;
	
	volt *= 2.0F;
	
	return volt;
}


void lv_anim_battery_cb(void* p, int32_t v)
{
    static int32_t cnt;
    float volt = battery_get_volt(battery_get_adc_value());  // ��ȡ��ص�ѹ
    uint8_t percentage = battery_get_percentage(volt);      // ��������ٷֱ�
    int32_t width = percentage * (OUTLINE_W - 4) / 100;     // �������������

    // ���� 20% ��ʾ��ɫ��������ɫ
    if (cnt >= OUTLINE_W * 0.2 && width < OUTLINE_W * 0.2)
    {
        lv_obj_set_style_bg_color(p, lv_color_hex(0xff0000), 0);
    }
    else if (width >= OUTLINE_W * 0.2 && cnt < OUTLINE_W * 0.2)
    {
        lv_obj_set_style_bg_color(p, lv_color_hex(0x00ff00), 0);
    }
    cnt = width;

    // �޸ĵ�����ɫ obj ���
    lv_obj_set_width(p, width);

    // �޸ĵ�ذٷֱ�
    lv_obj_t *text = lv_obj_get_child(lv_obj_get_parent(p), -1);
    lv_label_set_text_fmt(text, "%d%%", percentage);
}


void ui_battery_init(lv_ui *ui,lv_obj_t *obj)
{
   //Write codes Serial_img_1
	ui->Serial_img_1 = lv_img_create(obj); 
	lv_img_set_src(ui->Serial_img_1, &_33_alpha_16x16);
	lv_img_set_pivot(ui->Serial_img_1, 0,0);
	lv_img_set_angle(ui->Serial_img_1, 2700);
	lv_obj_set_pos(ui->Serial_img_1, 290, 10);
	lv_obj_set_size(ui->Serial_img_1, 16, 16);

	//Write style for Serial_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_img_opa(ui->Serial_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
}

void ui_battery_display(void)
{
	volatile uint32_t adc_value = battery_get_adc_value();
	volatile float volt = battery_get_volt(adc_value);  // ��ȡ��ص�ѹ
	
	if(BATTERY_PIN_STATUE == BATTERY_CHARGING)
	{
		lv_img_set_src(guider_ui.Serial_img_1, &_xx_alpha_16x16);
	}
	else if(volt >= 4.0F) //3
	{
		lv_img_set_src(guider_ui.Serial_img_1, &_33_alpha_16x16);
	}
	else if(volt < 4.0F && volt >= 3.7F) //2
	{
		lv_img_set_src(guider_ui.Serial_img_1, &_22_alpha_16x16);
	}
	else if(volt < 3.7F && volt >= 3.5F) // 1
	{
		lv_img_set_src(guider_ui.Serial_img_1, &_11_alpha_16x16);
	}
	else if(volt < 3.5F) // 0
	{
		lv_img_set_src(guider_ui.Serial_img_1, &_00_alpha_16x16);
	}
}





