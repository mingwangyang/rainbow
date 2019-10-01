#include "include.h"


/**
 * ��ʼ���������Ź�
 * prer:��Ƶ��:0~7(ֻ�е� 3 λ��Ч!)
 * ��Ƶ����=4*2^prer.�����ֵֻ���� 256!
 * rlr:��װ�ؼĴ���ֵ:�� 11 λ��Ч.
 * ʱ�����(���):Tout=((4*2^prer)*rlr)/40 (ms).
 *IWDG_Init(7,512);//��ʼ���������Ź�����Ƶ��Ϊ512��
 *��װ��ֵΪ512�����ʱ�����Ϊ��512*512/40=6553.6ms,ԼΪ6.5s
 */
void IWDG_Init(unsigned char prer,unsigned int rlr)
{
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); /* ʹ�ܶԼĴ���IWDG_PR��IWDG_RLR��д����*/
    IWDG_SetPrescaler(prer);    /*����IWDGԤ��Ƶֵ:����IWDGԤ��Ƶֵ*/
    IWDG_SetReload(rlr);     /*����IWDG��װ��ֵ*/
    IWDG_ReloadCounter();    /*����IWDG��װ�ؼĴ�����ֵ��װ��IWDG������*/
    IWDG_Enable();        /*ʹ��IWDG*/
}

/**
 * ι�������Ź�
 */
void IWDG_Feed(void)
{
    IWDG_ReloadCounter();    /*reload*/
}

///**
// *main����
// */
//void main(void)
//{
//  NVIC_Configuration();//���ȼ�����
//  IWDG_Init(4,625);//��ʼ���������Ź�����Ƶ��Ϊ64����װ��ֵΪ625�����ʱ�����Ϊ��64*625/40=1000ms=1s
//��while(1)
//����{
//��������delay_ms(500);//0.5��ιһ�ι�
//    ����IWDG_Feed();//ι��
//����}        
//}

