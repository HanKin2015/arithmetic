#ifndef CHINESE_H
#define CHINESE_H
#include "language.h"
static char* CN_start ="开始";
static char* CN_stop ="停止";
static char* CN_input ="请输入题目数量";
static char* CN_clear ="清零";
static char* CN_submit= "提交";
static char* CN_score ="分数";
static char* CN_second ="秒";
static char* CN_generate ="生成";
static char* CN_file = "文件(&F)";
static char* CN_openfile="&打开文件";
static char* CN_copyfile="复制文件";
static char* CN_exit="退出(&x)";
static char* CN_language="语言(&L)";
static char* CN_help="帮助(&H)";
static char* CN_params="&参数";
static char* CN_about="&关于";

#define CN_Set_Value(x) context->x = CN_##x;

void set_CN_context(Language_Context * context)
{
    CN_Set_Value(start)
    CN_Set_Value(stop)
    CN_Set_Value(input)
    CN_Set_Value(clear)
    CN_Set_Value(submit)
    CN_Set_Value(second)
    CN_Set_Value(score)
    CN_Set_Value(generate)
    CN_Set_Value(file)
    CN_Set_Value(openfile)
    CN_Set_Value(copyfile)
    CN_Set_Value(exit)
    CN_Set_Value(language)
    CN_Set_Value(help)
    CN_Set_Value(params)
    CN_Set_Value(about)
}

#endif
