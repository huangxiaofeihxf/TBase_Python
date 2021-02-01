/*
 * Tencent is pleased to support the open source community by making TBase available.  
 * 
 * Copyright (C) 2019 THL A29 Limited, a Tencent company.  All rights reserved.
 * 
 * TBase is licensed under the BSD 3-Clause License, except for the third-party component listed below. 
 * 
 * A copy of the BSD 3-Clause License is included in this file.
 * 
 * Other dependencies and licenses:
 * 
 * Open Source Software Licensed Under the PostgreSQL License: 
 * --------------------------------------------------------------------
 * 1. Postgres-XL XL9_5_STABLE
 * Portions Copyright (c) 2015-2016, 2ndQuadrant Ltd
 * Portions Copyright (c) 2012-2015, TransLattice, Inc.
 * Portions Copyright (c) 2010-2017, Postgres-XC Development Group
 * Portions Copyright (c) 1996-2015, The PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, The Regents of the University of California
 * 
 * Terms of the PostgreSQL License: 
 * --------------------------------------------------------------------
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without a written agreement
 * is hereby granted, provided that the above copyright notice and this
 * paragraph and the following two paragraphs appear in all copies.
 * 
 * IN NO EVENT SHALL THE UNIVERSITY OF CALIFORNIA BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING
 * LOST PROFITS, ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS
 * DOCUMENTATION, EVEN IF THE UNIVERSITY OF CALIFORNIA HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * 
 * THE UNIVERSITY OF CALIFORNIA SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE UNIVERSITY OF CALIFORNIA HAS NO OBLIGATIONS TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 * 
 * 
 * Terms of the BSD 3-Clause License:
 * --------------------------------------------------------------------
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation 
 * and/or other materials provided with the distribution.
 * 
 * 3. Neither the name of THL A29 Limited nor the names of its contributors may be used to endorse or promote products derived from this software without 
 * specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS 
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE 
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH 
 * DAMAGE.
 * 
 */
/*-------------------------------------------------------------------------
 *
 * pg_namespace.h
 *      definition of the system "namespace" relation (pg_namespace)
 *      along with the relation's initial contents.
 *
 *
 * Portions Copyright (c) 2012-2014, TransLattice, Inc.
 * Portions Copyright (c) 1996-2017, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/catalog/pg_namespace.h
 *
 * NOTES
 *      the genbki.pl script reads this file and generates .bki
 *      information from the DATA() statements.
 *
 *-------------------------------------------------------------------------
 */
#ifndef PG_NAMESPACE_H
#define PG_NAMESPACE_H

#include "catalog/genbki.h"

/* ----------------------------------------------------------------
 *        pg_namespace definition.
 *
 *        cpp turns this into typedef struct FormData_pg_namespace
 *
 *    nspname                name of the namespace
 *    nspowner            owner (creator) of the namespace
 *    nspacl                access privilege list
 * ----------------------------------------------------------------
 */
#define NamespaceRelationId  2615

CATALOG(pg_namespace,2615)
{
    NameData    nspname;
    Oid            nspowner;

#ifdef CATALOG_VARLEN            /* variable-length fields start here */
    aclitem        nspacl[1];
#endif
} FormData_pg_namespace;

/* ----------------
 *        Form_pg_namespace corresponds to a pointer to a tuple with
 *        the format of pg_namespace relation.
 * ----------------
 */
typedef FormData_pg_namespace *Form_pg_namespace;

/* ----------------
 *        compiler constants for pg_namespace
 * ----------------
 */

#define Natts_pg_namespace                3
#define Anum_pg_namespace_nspname        1
#define Anum_pg_namespace_nspowner        2
#define Anum_pg_namespace_nspacl        3


/* ----------------
 * initial contents of pg_namespace
 * ---------------
 */

DATA(insert OID = 11 ( "pg_catalog" PGUID _null_ ));
DESCR("system catalog schema");
#define PG_CATALOG_NAMESPACE 11
DATA(insert OID = 99 ( "pg_toast" PGUID _null_ ));
DESCR("reserved schema for TOAST tables");
#define PG_TOAST_NAMESPACE 99
DATA(insert OID = 2200 ( "public" PGUID _null_ ));
DESCR("standard public schema");
#define PG_PUBLIC_NAMESPACE 2200

#ifdef _PG_ORCL_
DATA(insert OID = 5500 ( "pg_oracle" PGUID _null_ ));
DESCR("new schema for oracle compatibility");
#define PG_ORACLE_NAMESPACE 5500
#endif

/*
 * prototypes for functions in pg_namespace.c
 */
extern Oid    NamespaceCreate(const char *nspName, Oid ownerId, bool isTemp);

#endif                            /* PG_NAMESPACE_H */
