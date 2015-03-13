/*
 * File      : finsh_var.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2010, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-03-22     Bernard      first version
 */
#ifndef __FINSH_VAR_H__
#define __FINSH_VAR_H__

#include <finsh.h>

/*
 * The variable in finsh is put in data segment as a global variable.
 * The 'finsh_var' structure presents the structure of variable in data segment.
 */
struct finsh_var
{
    char name[FINSH_NAME_MAX + 1];	/* the name of variable */

    u_char type;					/* the type of variable */

    /* variable value */
    union
    {
        char 	char_value;
        short 	short_value;
        int		int_value;
        long	long_value;
        void	*ptr;
    } value;
};
extern struct finsh_var global_variable[];

int finsh_var_init(void);
int finsh_var_insert(const char *name, int type);
int finsh_var_delete(const char *name);
struct finsh_var *finsh_var_lookup(const char *name);

#endif
