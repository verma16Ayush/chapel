/* -*-Mode: c++;-*-
*/
#ifndef _driver_H_
#define _driver_H_

#include <stdio.h>

#define DEFAULT_SYSTEM_DIR      "."

extern FILE* html_index_file;

// Begin temporary development flags
extern bool no_pre_instantiate;
extern bool no_remove_on_pre_instantiate;
extern bool no_infer;
extern bool formalTemps;
extern bool checkAnalysisTypeinfo;
// End temporary development flags

extern int instantiation_limit;

extern int fdump_html;
extern int f_equal_method;
extern int fnostdincs;
extern int fnostdincs_but_file;

extern int fgraph;

extern int run_interpreter;
extern int finterpreter_ast_mode;
extern int trace_level;
extern bool no_inline;
extern bool report_inlining;
extern char system_dir[FILENAME_MAX];

extern int debugParserLevel;
extern bool no_codegen;
extern bool developer;
extern int num_constants_per_variable;

extern bool ignore_errors;

void do_analysis(char *fn);

#endif
