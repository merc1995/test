/*
 * osdef.h is automagically created from osdef?.h.in by osdef.sh -- DO NOT EDIT
 */
/* autoconf cannot fiddle out declarations. Use our homebrewn tools. (jw) */
/*
 * Declarations that may cause conflicts belong here so that osdef.sh
 * can clean out the forest. Everything else belongs in os_unix.h
 *
 * How this works:
 * - This file contains all unix prototypes that Vim might need.
 * - The shell script osdef.sh is executed at compile time to remove all the
 *   prototypes that are in an include file. This results in osdef.h.
 * - osdef.h is included in vim.h.
 *
 * sed cannot always handle so many commands, this is file 1 of 2
 */

extern int	printf __ARGS((char *, ...));
extern int	fprintf __ARGS((FILE *, char *, ...));
extern int	sprintf __ARGS((char *, char *, ...));
extern int	sscanf __ARGS((char *, char *, ...));
#ifndef fopen	/* could be redefined to fopen64() */
extern FILE	*fopen __ARGS((const char *, const char *));
#endif
extern int	fclose __ARGS((FILE *));
extern int	fseek __ARGS((FILE *, long, int));
#ifdef HAVE_FSEEKO
extern int	fseeko __ARGS((FILE *, off_t, int));
#endif
extern long	ftell __ARGS((FILE *));
#ifdef HAVE_FSEEKO
extern off_t	ftello __ARGS((FILE *));
#endif
extern void	rewind __ARGS((FILE *));
extern int	fread __ARGS((char *, int, int, FILE *));
extern int	fwrite __ARGS((char *, int, int, FILE *));
extern int	fputs __ARGS((char *, FILE *));
#ifndef ferror	/* let me say it again: "macros should never have prototypes" */
extern int	ferror __ARGS((FILE *));
#endif
extern int	fflush __ARGS((FILE *));
#if defined(sun) || defined(_SEQUENT_)
/* used inside of stdio macros getc(), puts(), putchar()... */
extern int	_flsbuf __ARGS((int, FILE *));
extern int	_filbuf __ARGS((FILE *));
#endif

#if !defined(HAVE_SELECT)
struct pollfd;			/* for poll __ARGS */
extern int	poll __ARGS((struct pollfd *, long, int));
#endif

#ifdef HAVE_MEMSET
extern void	*memset __ARGS((void *, int, size_t));
#endif
#ifdef HAVE_BCMP
extern int	bcmp __ARGS((void *, void *, size_t));
#endif
#ifdef HAVE_MEMCMP
extern int	memcmp __ARGS((const void *, const void *, size_t));
#endif
#ifdef HAVE_STRPBRK
extern char	*strpbrk __ARGS((const char *, const char *));
#endif
#ifdef USEBCOPY
extern void	bcopy __ARGS((char *, char *, int));
#else
# ifdef USEMEMCPY
extern void	memcpy __ARGS((char *, char *, int));
# else
#  ifdef USEMEMMOVE
extern void	memmove __ARGS((char *, char *, int));
#  endif
# endif
#endif
/* used inside of FD_ZERO macro: */
extern void	bzero __ARGS((void *, size_t));
#ifdef HAVE_SETSID
extern pid_t	setsid __ARGS((void));
#endif
#ifdef HAVE_SETPGID
extern int	setpgid __ARGS((pid_t, pid_t));
#endif
#ifdef HAVE_STRTOL
extern int	strtol __ARGS((char *, char **, int));
#endif
#ifdef HAVE_STRFTIME
extern size_t	strftime __ARGS((char *, size_t, char *, struct tm *));
#endif
#ifdef HAVE_STRCASECMP
extern int	strcasecmp __ARGS((char *, char *));
#endif
#ifdef HAVE_STRNCASECMP
extern int	strncasecmp __ARGS((char *, char *, size_t));
#endif
#ifndef strdup
extern char	*strdup __ARGS((const char *));
#endif
extern int	atoi __ARGS((char *));
extern int	atol __ARGS((char *));

#ifndef USE_SYSTEM
extern int	fork __ARGS((void));
# ifndef __TANDEM
extern int	execvp __ARGS((const char *, const char **));
# endif
extern int	wait __ARGS((int *)); /* will this break things ...? */
extern int	waitpid __ARGS((pid_t, int *, int));
#endif

extern int	toupper __ARGS((int));
extern int	tolower __ARGS((int));

extern RETSIGTYPE (*signal __ARGS((int, RETSIGTYPE (*func) SIGPROTOARG))) __ARGS(SIGPROTOARG);
#ifdef HAVE_SIGSET
extern RETSIGTYPE (*sigset __ARGS((int, RETSIGTYPE (*func) SIGPROTOARG))) __ARGS(SIGPROTOARG);
#endif

#if defined(HAVE_SETJMP_H)
# ifdef HAVE_SIGSETJMP
extern int	sigsetjmp __ARGS((sigjmp_buf, int));
extern void	siglongjmp __ARGS((sigjmp_buf, int));
# else
extern int	setjmp __ARGS((jmp_buf));
extern void	longjmp __ARGS((jmp_buf, int));
# endif
#endif

extern int	kill __ARGS((int, int));

#ifndef __TANDEM
extern int	access __ARGS((char *, int));
#endif
extern int	fsync __ARGS((int));
extern int	fchown __ARGS((int, int, int));
#if defined(HAVE_GETCWD) && !defined(sun) && !defined(__TANDEM)
extern char	*getcwd __ARGS((char *, int));
#else
extern char	*getwd __ARGS((char *));
#endif
#ifndef __alpha	/* suggested by Campbell */
extern int	ioctl __ARGS((int, int, ...));
#endif
extern int	chmod __ARGS((const char *, mode_t));
/*
 * osdef2.h.in - See osdef1.h.in for a description.
 */

extern int	remove __ARGS((const char *));
extern int	rename __ARGS((const char *, const char *));
extern int	free __ARGS((char *));
extern char	*malloc __ARGS((unsigned int));
extern char	*realloc __ARGS((char *, int));
extern char	*getenv __ARGS((char *));
extern int	setenv __ARGS((char *, char *, int));
extern int	putenv __ARGS((const char *));

#ifndef __TANDEM
extern int	gethostname __ARGS((char *, int));
#endif
extern void	perror __ARGS((char *));

#ifndef __TANDEM
extern int	sleep __ARGS((int));
#endif
extern int	usleep __ARGS((unsigned int));
extern unsigned int	alarm __ARGS((unsigned int));
#ifndef __TANDEM
extern int	chdir __ARGS((char *));
#endif
extern int	fchdir __ARGS((int));
#ifndef stat	/* could be redefined to stat64() */
extern int	stat __ARGS((const char *, struct stat *));
#endif
#ifndef lstat	/* could be redefined to lstat64() */
extern int	lstat __ARGS((const char *, struct stat *));
#endif
extern int	fstat __ARGS((int, struct stat *));
extern int	open __ARGS((const char *, int, ...));
extern int	close __ARGS((int));
#ifndef __TANDEM
extern int	read __ARGS((int, char *, size_t));
extern int	write __ARGS((int, char *, size_t));
#endif
extern int	pipe __ARGS((int *));
extern off_t	lseek __ARGS((int, off_t, int));
extern void	sync __ARGS((void));
extern uid_t	getuid __ARGS((void));
extern gid_t	getgid __ARGS((void));
extern void	qsort __ARGS((void *, size_t, size_t, int (*)(const void *, const void *)));

extern int	isatty __ARGS((int));
extern int	getpid __ARGS((void));
extern int	dup __ARGS((int));
extern int	unlink __ARGS((const char *));
extern int	link __ARGS((const char *, const char *));
extern int	mkdir __ARGS((const char *, mode_t));
extern int	rmdir __ARGS((const char *));

extern int	tgetent __ARGS((char *, char *));
extern int	tgetnum __ARGS((char *));
extern int	tgetflag __ARGS((char *));
extern char	*tgoto __ARGS((char *, int, int));
extern int	tputs __ARGS((char *, int, int (*)(int)));

#ifdef HAVE_TERMIOS_H
struct termios;		/* for tcgetattr __ARGS */
extern int	tcgetattr __ARGS((int, struct termios *));
extern int	tcsetattr __ARGS((int, int, const struct termios *));
#endif

#ifdef HAVE_SYS_STATFS_H
struct statfs;		/* for fstatfs __ARGS */
extern int	fstatfs __ARGS((int, struct statfs *, int, int));
#endif

#ifdef HAVE_GETTIMEOFDAY
struct timeval;		/* for gettimeofday __ARGS */
struct timezone;	/* for gettimeofday __ARGS */
extern int	gettimeofday __ARGS((struct timeval *tp, struct timezone *tzp));
extern time_t	time __ARGS((time_t *));
#endif

#ifdef HAVE_GETPWNAM
struct passwd;		/* for getpwnam __ARGS */
extern struct passwd *getpwnam __ARGS((const char *));
#endif

#ifdef USE_TMPNAM
extern char	*tmpnam __ARGS((char *));
#else
extern char	*mktemp __ARGS((char *));
#endif

#ifdef ISC
extern int	_Xmblen __ARGS((char const *, size_t));
#else
		/* This is different from the header but matches mblen() */
extern int	_Xmblen __ARGS((char *, size_t));
#endif
