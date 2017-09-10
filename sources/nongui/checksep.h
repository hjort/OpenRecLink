#ifndef CHECKSEP_H_INCLUDED
#define CHECKSEP_H_INCLUDED

extern bool convertOK;

#define CVTFROM ((convertOK) ? _(",") : _("."))
//#define CVTFROM ((convertOK)?",":".")
#define CVTTO   ((convertOK) ? _(".") : _(","))
//#define CVTTO   ((convertOK)?".":",")

#endif // CHECKSEP_H_INCLUDED
