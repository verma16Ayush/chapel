/* -*-Mode: c++;-*-
*/
#ifndef _code_h_
#define _code_h_

#include "defs.h"

class Label;
class Prim;
class PNode;
class Sym;

enum Code_kind { 
  Code_SUB = 0, Code_MOVE, Code_SEND, Code_IF, Code_LABEL, 
  Code_GOTO, Code_SEQ, Code_CONC, Code_NOP
};

enum Partial_kind { Partial_OK = 0, Partial_NEVER = 1, Partial_ALWAYS = 2 };

extern char *code_string[];

class Code;
void testme(Code *);

class Code : public gc {
 public:
  Code_kind     kind;
  //the variables this node reads
  Vec<Sym *>    rvals;
  //the variables this node assigns
  Vec<Sym *>    lvals;
  Label         *label[2];
  Vec<Code *>   sub;
  IFAAST        *ast;
  Prim          *prim;

  char          *pathname();
  char          *filename();
  int           line();
  int           log_line(); // squelch line number in prelude (for testing)

  unsigned int  partial:2;
  unsigned int  live:1;
  unsigned int  dead:1; // used by if1.cpp
  unsigned int  flattened:1;
  Code          *cont;  // used by cfg.cpp
  PNode         *pn;    // used by cfg.cpp

  Code(Code_kind k = Code_SUB) { memset(this, 0, sizeof *this); kind = k; testme(this); }
  int is_group() { return kind == Code_SUB || kind == Code_SEQ || kind == Code_CONC; }
};
#define forv_Code(_c, _v) forv_Vec(Code, _c, _v)

class Label : public gc {
 public:
  int                   id;
  unsigned int          live:1;
  Code                  *code;                  // used by fun.cpp

  Label() { memset(this, 0, sizeof *this); }
};


#endif
