/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_BASE_YY_GRAM_H_INCLUDED
# define YY_BASE_YY_GRAM_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int base_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    FCONST = 259,
    SCONST = 260,
    BCONST = 261,
    XCONST = 262,
    Op = 263,
    ICONST = 264,
    PARAM = 265,
    TYPECAST = 266,
    DOT_DOT = 267,
    COLON_EQUALS = 268,
    EQUALS_GREATER = 269,
    LESS_EQUALS = 270,
    GREATER_EQUALS = 271,
    NOT_EQUALS = 272,
    ABORT_P = 273,
    ABSOLUTE_P = 274,
    ACCESS = 275,
    ACTION = 276,
    ADD_P = 277,
    ADMIN = 278,
    AFTER = 279,
    AGGREGATE = 280,
    ALL = 281,
    ALSO = 282,
    ALTER = 283,
    ALWAYS = 284,
    ANALYSE = 285,
    ANALYZE = 286,
    AND = 287,
    ANY = 288,
    ARRAY = 289,
    AS = 290,
    ASC = 291,
    ASSERTION = 292,
    ASSIGNMENT = 293,
    ASYMMETRIC = 294,
    AT = 295,
    ATTACH = 296,
    ATTRIBUTE = 297,
    AUDIT = 298,
    AUTHORIZATION = 299,
    BACKWARD = 300,
    BARRIER = 301,
    BEFORE = 302,
    BEGIN_P = 303,
    BEGIN_SUBTXN = 304,
    BETWEEN = 305,
    BIGINT = 306,
    BINARY = 307,
    BINARY_FLOAT = 308,
    BINARY_DOUBLE = 309,
    BIT = 310,
    BOOLEAN_P = 311,
    BOTH = 312,
    BY = 313,
    CACHE = 314,
    CALLED = 315,
    CASCADE = 316,
    CASCADED = 317,
    CASE = 318,
    CAST = 319,
    CATALOG_P = 320,
    CHAIN = 321,
    CHAR_P = 322,
    CHARACTER = 323,
    CHARACTERISTICS = 324,
    CHECK = 325,
    CHECKPOINT = 326,
    CLASS = 327,
    CLEAN = 328,
    CLOSE = 329,
    CLUSTER = 330,
    COALESCE = 331,
    COLLATE = 332,
    COLLATION = 333,
    COLUMN = 334,
    COLUMNS = 335,
    COMMENT = 336,
    COMMENTS = 337,
    COMMIT = 338,
    COMMIT_SUBTXN = 339,
    COMMITTED = 340,
    CONCURRENTLY = 341,
    CONFIGURATION = 342,
    CONFLICT = 343,
    CONNECTION = 344,
    CONSTRAINT = 345,
    CONSTRAINTS = 346,
    CONTENT_P = 347,
    CONTINUE_P = 348,
    CONVERSION_P = 349,
    COORDINATOR = 350,
    COPY = 351,
    COST = 352,
    CREATE = 353,
    CROSS = 354,
    CSV = 355,
    CUBE = 356,
    CURRENT_P = 357,
    CURRENT_CATALOG = 358,
    CURRENT_DATE = 359,
    CURRENT_ROLE = 360,
    CURRENT_SCHEMA = 361,
    CURRENT_TIME = 362,
    CURRENT_TIMESTAMP = 363,
    CURRENT_USER = 364,
    CURSOR = 365,
    CYCLE = 366,
    DATA_P = 367,
    DATABASE = 368,
    DAY_P = 369,
    DBTIMEZONE = 370,
    DEALLOCATE = 371,
    DEC = 372,
    DECIMAL_P = 373,
    DECLARE = 374,
    DEFAULT = 375,
    DEFAULTS = 376,
    DEFERRABLE = 377,
    DEFERRED = 378,
    DEFINER = 379,
    DELETE_P = 380,
    DELIMITER = 381,
    DELIMITERS = 382,
    DEPENDS = 383,
    DESC = 384,
    DETACH = 385,
    DICTIONARY = 386,
    DIRECT = 387,
    DISABLE_P = 388,
    DISCARD = 389,
    DISTINCT = 390,
    DISTKEY = 391,
    DISTRIBUTE = 392,
    DISTRIBUTED = 393,
    DISTSTYLE = 394,
    DO = 395,
    DOCUMENT_P = 396,
    DOMAIN_P = 397,
    DOUBLE_P = 398,
    DROP = 399,
    EACH = 400,
    ELSE = 401,
    ENABLE_P = 402,
    ENCODING = 403,
    ENCRYPTED = 404,
    END_P = 405,
    ENUM_P = 406,
    ESCAPE = 407,
    EVENT = 408,
    EXCEPT = 409,
    EXCHANGE = 410,
    EXCLUDE = 411,
    EXCLUDING = 412,
    EXCLUSIVE = 413,
    EXECUTE = 414,
    EXISTS = 415,
    EXPLAIN = 416,
    EXTENSION = 417,
    EXTENT = 418,
    EXTERNAL = 419,
    EXTRACT = 420,
    FALSE_P = 421,
    FAMILY = 422,
    FETCH = 423,
    FILTER = 424,
    FIRST_P = 425,
    FLOAT_P = 426,
    FOLLOWING = 427,
    FOR = 428,
    FORCE = 429,
    FOREIGN = 430,
    FORWARD = 431,
    FREEZE = 432,
    FROM = 433,
    FULL = 434,
    FUNCTION = 435,
    FUNCTIONS = 436,
    GENERATED = 437,
    GLOBAL = 438,
    GRANT = 439,
    GRANTED = 440,
    GREATEST = 441,
    GROUP_P = 442,
    GROUPING = 443,
    GTM = 444,
    HANDLER = 445,
    HAVING = 446,
    HEADER_P = 447,
    HOLD = 448,
    HOUR_P = 449,
    IDENTITY_P = 450,
    IF_P = 451,
    ILIKE = 452,
    IMMEDIATE = 453,
    IMMUTABLE = 454,
    IMPLICIT_P = 455,
    IMPORT_P = 456,
    IN_P = 457,
    INCLUDING = 458,
    INCREMENT = 459,
    INDEX = 460,
    INDEXES = 461,
    INHERIT = 462,
    INHERITS = 463,
    INITIALLY = 464,
    INLINE_P = 465,
    INNER_P = 466,
    INOUT = 467,
    INPUT_P = 468,
    INSENSITIVE = 469,
    INSERT = 470,
    INSTEAD = 471,
    INT_P = 472,
    INTEGER = 473,
    INTERSECT = 474,
    INTERVAL = 475,
    INTO = 476,
    INVOKER = 477,
    IS = 478,
    ISNULL = 479,
    ISOLATION = 480,
    JOIN = 481,
    KEY = 482,
    LABEL = 483,
    LANGUAGE = 484,
    LARGE_P = 485,
    LAST_P = 486,
    LATERAL_P = 487,
    LEADING = 488,
    LEAKPROOF = 489,
    LEAST = 490,
    LEFT = 491,
    LEVEL = 492,
    LIKE = 493,
    LIMIT = 494,
    LISTEN = 495,
    LOAD = 496,
    LOCAL = 497,
    LOCALTIME = 498,
    LOCALTIMESTAMP = 499,
    LOCATION = 500,
    LOCK_P = 501,
    LOCKED = 502,
    LOGGED = 503,
    MAPPING = 504,
    MATCH = 505,
    MATERIALIZED = 506,
    MAXVALUE = 507,
    METHOD = 508,
    MINUTE_P = 509,
    MINVALUE = 510,
    MODE = 511,
    MONTH_P = 512,
    MOVE = 513,
    NAME_P = 514,
    NAMES = 515,
    NATIONAL = 516,
    NATURAL = 517,
    NCHAR = 518,
    NEW = 519,
    NEXT = 520,
    NO = 521,
    NOAUDIT = 522,
    NODE = 523,
    NONE = 524,
    NOT = 525,
    NOTHING = 526,
    NOTIFY = 527,
    NOTNULL = 528,
    NOWAIT = 529,
    NULL_P = 530,
    NULLIF = 531,
    NULLS_P = 532,
    NUMBER = 533,
    NUMERIC = 534,
    OBJECT_P = 535,
    OF = 536,
    OFF = 537,
    OFFSET = 538,
    OID_P = 539,
    OIDS = 540,
    OLD = 541,
    ON = 542,
    ONLY = 543,
    OPERATOR = 544,
    OPTION = 545,
    OPTIONS = 546,
    OR = 547,
    ORDER = 548,
    ORDINALITY = 549,
    OUT_P = 550,
    OUTER_P = 551,
    OVER = 552,
    OVERLAPS = 553,
    OVERLAY = 554,
    OVERRIDING = 555,
    OWNED = 556,
    OWNER = 557,
    PARALLEL = 558,
    PARSER = 559,
    PARTIAL = 560,
    PARTITION = 561,
    PARTITIONS = 562,
    PASSING = 563,
    PASSWORD = 564,
    PAUSE = 565,
    PLACING = 566,
    PLANS = 567,
    POLICY = 568,
    POSITION = 569,
    PRECEDING = 570,
    PRECISION = 571,
    PREFERRED = 572,
    PRESERVE = 573,
    PREPARE = 574,
    PREPARED = 575,
    PRIMARY = 576,
    PRIOR = 577,
    PRIVILEGES = 578,
    PROCEDURAL = 579,
    PROCEDURE = 580,
    PROGRAM = 581,
    PUBLICATION = 582,
    QUOTE = 583,
    RANDOMLY = 584,
    RANGE = 585,
    READ = 586,
    REAL = 587,
    REASSIGN = 588,
    REBUILD = 589,
    RECHECK = 590,
    RECURSIVE = 591,
    REF = 592,
    REFERENCES = 593,
    REFERENCING = 594,
    REFRESH = 595,
    REINDEX = 596,
    RELATIVE_P = 597,
    RELEASE = 598,
    RENAME = 599,
    REPEATABLE = 600,
    REPLACE = 601,
    REPLICA = 602,
    RESET = 603,
    RESTART = 604,
    RESTRICT = 605,
    RETURNING = 606,
    RETURNS = 607,
    REVOKE = 608,
    RIGHT = 609,
    ROLE = 610,
    ROLLBACK = 611,
    ROLLBACK_SUBTXN = 612,
    ROLLUP = 613,
    ROW = 614,
    ROWS = 615,
    RULE = 616,
    SAMPLE = 617,
    SAVEPOINT = 618,
    SCHEMA = 619,
    SCHEMAS = 620,
    SCROLL = 621,
    SEARCH = 622,
    SECOND_P = 623,
    SECURITY = 624,
    SELECT = 625,
    SEQUENCE = 626,
    SEQUENCES = 627,
    SERIALIZABLE = 628,
    SERVER = 629,
    SESSION = 630,
    SESSION_USER = 631,
    SESSIONTIMEZONE = 632,
    SET = 633,
    SETS = 634,
    SETOF = 635,
    SHARDING = 636,
    SHARE = 637,
    SHOW = 638,
    SIMILAR = 639,
    SIMPLE = 640,
    SKIP = 641,
    SLOT = 642,
    SMALLINT = 643,
    SNAPSHOT = 644,
    SOME = 645,
    SQL_P = 646,
    STABLE = 647,
    STANDALONE_P = 648,
    START = 649,
    STATEMENT = 650,
    STATISTICS = 651,
    STDIN = 652,
    STDOUT = 653,
    STEP = 654,
    STORAGE = 655,
    STRICT_P = 656,
    STRIP_P = 657,
    SUBSCRIPTION = 658,
    SUBSTRING = 659,
    SUCCESSFUL = 660,
    SYMMETRIC = 661,
    SYSDATE = 662,
    SYSID = 663,
    SYSTEM_P = 664,
    SYSTIMESTAMP = 665,
    TABLE = 666,
    TABLES = 667,
    TABLESAMPLE = 668,
    TABLESPACE = 669,
    TBASE_P = 670,
    TEMP = 671,
    TEMPLATE = 672,
    TEMPORARY = 673,
    TEXT_P = 674,
    THEN = 675,
    TIME = 676,
    TIMESTAMP = 677,
    TO = 678,
    TRAILING = 679,
    TRANSACTION = 680,
    TRANSFORM = 681,
    TREAT = 682,
    TRIGGER = 683,
    TRIM = 684,
    TRUE_P = 685,
    TRUNCATE = 686,
    TRUSTED = 687,
    TYPE_P = 688,
    TYPES_P = 689,
    UNBOUNDED = 690,
    UNCOMMITTED = 691,
    UNENCRYPTED = 692,
    UNION = 693,
    UNIQUE = 694,
    UNKNOWN = 695,
    UNLISTEN = 696,
    UNLOCK_P = 697,
    UNLOGGED = 698,
    UNPAUSE = 699,
    UNTIL = 700,
    UPDATE = 701,
    USER = 702,
    USING = 703,
    VACUUM = 704,
    VALID = 705,
    VALIDATE = 706,
    VALIDATOR = 707,
    VALUE_P = 708,
    VALUES = 709,
    VARCHAR = 710,
    VARIADIC = 711,
    VARYING = 712,
    VERBOSE = 713,
    VERSION_P = 714,
    VIEW = 715,
    VIEWS = 716,
    VOLATILE = 717,
    WHEN = 718,
    WHENEVER = 719,
    WHERE = 720,
    WHITESPACE_P = 721,
    WINDOW = 722,
    WITH = 723,
    WITHIN = 724,
    WITHOUT = 725,
    WORK = 726,
    WRAPPER = 727,
    WRITE = 728,
    XML_P = 729,
    XMLATTRIBUTES = 730,
    XMLCONCAT = 731,
    XMLELEMENT = 732,
    XMLEXISTS = 733,
    XMLFOREST = 734,
    XMLNAMESPACES = 735,
    XMLPARSE = 736,
    XMLPI = 737,
    XMLROOT = 738,
    XMLSERIALIZE = 739,
    XMLTABLE = 740,
    YEAR_P = 741,
    YES_P = 742,
    ZONE = 743,
    NOT_LA = 744,
    NULLS_LA = 745,
    WITH_LA = 746,
    POSTFIXOP = 747,
    UMINUS = 748
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 217 "gram.y" /* yacc.c:1909  */

	core_YYSTYPE		core_yystype;
	/* these fields must match core_YYSTYPE: */
	int					ival;
	char				*str;
	const char			*keyword;

	char				chr;
	bool				boolean;
	JoinType			jtype;
	DropBehavior		dbehavior;
	OnCommitAction		oncommit;
	List				*list;
	Node				*node;
	Value				*value;
	ObjectType			objtype;
	TypeName			*typnam;
	FunctionParameter   *fun_param;
	FunctionParameterMode fun_param_mode;
	ObjectWithArgs		*objwithargs;
	DefElem				*defelt;
	SortBy				*sortby;
	WindowDef			*windef;
	JoinExpr			*jexpr;
	IndexElem			*ielem;
	Alias				*alias;
	RangeVar			*range;
	IntoClause			*into;
	WithClause			*with;
	InferClause			*infer;
	OnConflictClause	*onconflict;
	A_Indices			*aind;
	ResTarget			*target;
	struct PrivTarget	*privtarget;
	AccessPriv			*accesspriv;
	struct ImportQual	*importqual;
	InsertStmt			*istmt;
	VariableSetStmt		*vsetstmt;
/* PGXC_BEGIN */
	DistributeBy		*distby;
	PGXCSubCluster		*subclus;
/* PGXC_END */
	A_Const				*a_const;
	PartitionElem		*partelem;
	PartitionSpec		*partspec;
	PartitionBoundSpec	*partboundspec;
	RoleSpec			*rolespec;
	PartitionForExpr	*partfor;
	PartitionBy         *partby; 

#line 599 "gram.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int base_yyparse (core_yyscan_t yyscanner);

#endif /* !YY_BASE_YY_GRAM_H_INCLUDED  */
