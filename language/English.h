#ifndef ENGLISH_H
#define ENGLISH_H
#include "language.h"
static char* EN_start ="start";
static char* EN_stop ="stop";
static char* EN_input ="input the number of questions";
static char* EN_clear ="clear";
static char* EN_submit= "submit";
static char* EN_score ="score";
static char* EN_second ="s";
static char* EN_generate ="generate";
static char* EN_file = "File(&F)";
static char* EN_openfile="&open";
static char* EN_copyfile="copy";
static char* EN_exit="exit(&x)";
static char* EN_language="language(&L)";
static char* EN_help="help(&H)";
static char* EN_params="&parameter";
static char* EN_about="&about";
static char* EN_record="record";
static char* EN_history="history:";
static char* EN_mtime="time:";
static char* EN_unit="pt";
static char* EN_reset="reset";
static char* EN_formula="formula";
static char* EN_answer="answer";
static char* EN_uinput="input";
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
    EN_Set_Value(record)
    EN_Set_Value(history)
    EN_Set_Value(mtime)
    EN_Set_Value(unit)
    EN_Set_Value(reset)
    EN_Set_Value(formula)
    EN_Set_Value(answer)
    EN_Set_Value(uinput)
}

#endif
