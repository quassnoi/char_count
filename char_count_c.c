#include "postgres.h"
#include "fmgr.h"
#include "utils/builtins.h"

#if PG_VERSION_NUM >= 150000
#include "varatt.h"
#endif

PG_MODULE_MAGIC;

PG_FUNCTION_INFO_V1(char_count_c);

Datum
char_count_c(PG_FUNCTION_ARGS)
{
        int charCount = 0;
        int i = 0;
        text * inputText = PG_GETARG_TEXT_PP(0);
        text * targetChar = PG_GETARG_TEXT_PP(1);

	int inputText_sz = VARSIZE(inputText)-VARHDRSZ;
	int targetChar_sz = VARSIZE(targetChar)-VARHDRSZ;
	/*        int inputText_sz = PG_GETARG_INT32(0);
		  int targetChar_sz = PG_GETARG_INT32(1);*/

        char * cp_inputText = NULL;
        char * cp_targetChar = NULL;

        if ( targetChar_sz > 1 )
        {
                elog(ERROR, "arg1 must be 1 char long");
        }

        cp_inputText = (char *) palloc ( inputText_sz + 1);
        cp_targetChar = (char *) palloc ( targetChar_sz + 1);
        memcpy(cp_inputText, VARDATA(inputText), inputText_sz);
        memcpy(cp_targetChar, VARDATA(targetChar), targetChar_sz);

        elog(INFO, "arg0 length is %d, value %s", (int)strlen(cp_inputText), cp_inputText );
        elog(INFO, "arg1 length is %d, value %s", (int)strlen(cp_targetChar), cp_targetChar );

        while ( i < strlen(cp_inputText) )
        {
                if( cp_inputText[i] == cp_targetChar[0] )
                        charCount++;
                i++;
        }

        pfree(cp_inputText);
        pfree(cp_targetChar);
        PG_RETURN_INT32(charCount);
}
