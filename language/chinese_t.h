#ifndef CHINESE_T_H
#define CHINESE_T_H
#include "language.h"
static char* CN_T_start ="開始";
static char* CN_T_stop ="停止";
static char* CN_T_input ="請輸入題目數量";
static char* CN_T_clear ="清零";
static char* CN_T_submit= "提交";
static char* CN_T_score ="分數:";
static char* CN_T_second ="秒";
static char* CN_T_generate ="生成";
static char* CN_T_file = "文件(&F)";
static char* CN_T_openfile="&打開文件";
static char* CN_T_copyfile="複製文件";
static char* CN_T_exit="退出(&x)";
static char* CN_T_language="語言(&L)";
static char* CN_T_help="幫助(&H)";
static char* CN_T_params="&參數";
static char* CN_T_about="&關於";
static char* CN_T_record="記錄(&R)";
static char* CN_T_history="歷史記錄:";
static char* CN_T_mtime="時間:";
static char* CN_T_unit="分";
static char* CN_T_reset="重置";
static char* CN_T_formula="算式";
static char* CN_T_answer="正確答案";
static char* CN_T_uinput="输入";
#define CN_T_Set_Value(x) context->x = CN_T_##x;

void set_CN_T_context(Language_Context * context)
{
    CN_T_Set_Value(start)
    CN_T_Set_Value(stop)
    CN_T_Set_Value(input)
    CN_T_Set_Value(clear)
    CN_T_Set_Value(submit)
    CN_T_Set_Value(second)
    CN_T_Set_Value(score)
    CN_T_Set_Value(generate)
    CN_T_Set_Value(file)
    CN_T_Set_Value(openfile)
    CN_T_Set_Value(copyfile)
    CN_T_Set_Value(exit)
    CN_T_Set_Value(language)
    CN_T_Set_Value(help)
    CN_T_Set_Value(params)
    CN_T_Set_Value(about)
    CN_T_Set_Value(record)
    CN_T_Set_Value(history)
    CN_T_Set_Value(mtime)
    CN_T_Set_Value(unit)
    CN_T_Set_Value(reset)
    CN_T_Set_Value(formula)
    CN_T_Set_Value(answer)
    CN_T_Set_Value(uinput)
}

#endif // CHINESE_T_H
