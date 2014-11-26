/****************************************************************************/
/*                                                                          */
/*  This file is part of QSopt_ex.                                          */
/*                                                                          */
/*  (c) Copyright 2006 by David Applegate, William Cook, Sanjeeb Dash,      */
/*  and Daniel Espinoza                                                     */
/*                                                                          */
/*  Sanjeeb Dash ownership of copyright in QSopt_ex is derived from his     */
/*  copyright in QSopt.                                                     */
/*                                                                          */
/*  This code may be used under the terms of the GNU General Public License */
/*  (Version 2.1 or later) as published by the Free Software Foundation.    */
/*                                                                          */
/*  Alternatively, use is granted for research purposes only.               */
/*                                                                          */
/*  It is your choice of which of these two licenses you are operating      */
/*  under.                                                                  */
/*                                                                          */
/*  We make no guarantees about the correctness or usefulness of this code. */
/*                                                                          */
/****************************************************************************/

/* RCS_INFO = "$Id: line_reader.c,v 1.2 2003/11/05 16:49:52 meven Exp $"; */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>

#include "eg_io.h"
#include "iqsutil.h"
#include "readline.h"


/* #ifdef _WINDOWS*/
qsline_reader *ILLline_reader_new (
	qsread_line_fct fct,
	void *data_src)
{
	qsline_reader *reader;
	int rval = 0;

	ILL_NEW (reader, qsline_reader);
	if (reader != NULL)
	{
		reader->read_line_fct = fct;
		reader->data_src = data_src;
		reader->error_collector = NULL;
	}
CLEANUP:
	return reader;
}

void ILLline_reader_free (
	qsline_reader * reader)
{
	ILL_IFFREE (reader, qsline_reader);
}

/* #endif */
