#if !(defined(__TCC__) && defined(__CC2__))

#ifndef __STDIO
#define __STDIO

#define _IOFBF 0
#define _IOLBF 0100
#define _IONBF 04
#define BUFSIZ 1024
#define EOF (-1)

extern struct _iobuf {
	int	_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	int	_bufsiz;
	short	_flag;
	short	_file;
} _iob[];
#define FILE struct _iobuf
#define FILENAME_MAX 256
#define FOPEN_MAX 64

typedef long fpos_t;

#define L_tmpnam 25
#define NULL 0
#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

#if !defined(_SIZE_T) && !defined(_SIZE_T_)
#define _SIZE_T
#define _SIZE_T_
typedef unsigned size_t;
#endif

#define stderr (&_iob[2])
#define stdin (&_iob[0])
#define stdout (&_iob[1])
#define TMP_MAX 17576

extern int remove(const char *);
extern int rename(const char *, const char *);
extern FILE *tmpfile(void);
extern char *tmpnam(char *);
extern int fclose(FILE *);
extern int fflush(FILE *);
extern FILE *fopen(const char *, const char *);
extern FILE *freopen(const char *, const char *, FILE *);
extern void setbuf(FILE *, char *);
extern int setvbuf(FILE *, char *, int, size_t);
extern int fprintf(FILE *, const char *, ...);
extern int fscanf(FILE *, const char *, ...);
extern int printf(const char *, ...);
extern int scanf(const char *, ...);
extern int sprintf(char *, const char *, ...);
extern int sscanf(const char *, const char *, ...);
extern int vfprintf(FILE *, const char *, char *);
extern int vprintf(const char *, char *);
extern int vsprintf(char *, const char *, char *);
extern int fgetc(FILE *);
extern char *fgets(char *, int, FILE *);
extern int fputc(int, FILE *);
extern int fputs(const char *, FILE *);
extern int getc(FILE *);
extern int getchar(void);
extern char *gets(char *);
extern int putc(int, FILE *);
extern int putchar(int);
extern int puts(const char *);
extern int ungetc(int, FILE *);
extern size_t fread(void *, size_t, size_t, FILE *);
extern size_t fwrite(const void *, size_t, size_t, FILE *);
extern int fgetpos(FILE *, fpos_t *);
extern int fseek(FILE *, long int, int);
extern int fsetpos(FILE *, const fpos_t *);
extern long int ftell(FILE *);
extern void rewind(FILE *);
extern void clearerr(FILE *);
extern int feof(FILE *);
extern int ferror(FILE *);
extern void perror(const char *);

#define	_IOEOF 020
#define	_IOERR 040

#define getc(p) (--(p)->_cnt < 0 ? _filbuf(p) : (int) *(p)->_ptr++)
#define putc(x, p) (--(p)->_cnt < 0 ? _flsbuf((unsigned char) (x), p) : (int) (*(p)->_ptr++ = (unsigned char) (x)))
extern int _filbuf(FILE *), _flsbuf(unsigned, FILE *);
#define feof(p) ((p)->_flag&_IOEOF)
#define ferror(p) ((p)->_flag&_IOERR)
#define	clearerr(p) ((p)->_flag &= ~(_IOERR|_IOEOF))
#define	getchar() getc(stdin)
#define	putchar(x) putc((x),stdout)

#endif /* __STDIO */

#endif /* !(__TCC__ && __CC2__) */
