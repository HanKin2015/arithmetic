#ifndef ENGLISH_H
#define ENGLISH_H
#include "language.h"
static char* EN_start ="start";
static char* EN_stop ="stop";
static char* EN_input ="input the number of question";
static char* EN_clear ="clear";
static char* EN_submit= "submit";
static char* EN_score ="points";
static char* EN_second ="s";
static char* EN_generate ="generate";
static char* EN_file = "File(&F)";
static char* EN_openfile="&open";
static char* EN_copyfile="copy";
static char* EN_exit="exit(&x)";
static char* EN_language="language(&)";
static char* EN_help="help(&H)";
static char* EN_params="&parameter";
static char* EN_about="&about";

#define EN_Set_Value(x) context->x = EN_##x;

void set_EN_context(Language_Context * context)
{
    EN_Set_Value(start)
    EN_Set_Value(stop)
    EN_Set_Value(input)
    EN_Set_Value(clear)
    EN_Set_Value(submit)
    EN_Set_Value(score)
    EN_Set_Value(second)
    EN_Set_Value(generate)
    EN_Set_Value(file)
    EN_Set_Value(openfile)
    EN_Set_Value(copyfile)
    EN_Set_Value(exit)
    EN_Set_Value(language)
    EN_Set_Value(help)
    EN_Set_Value(params)
    EN_Set_Value(about)
}

#endif
