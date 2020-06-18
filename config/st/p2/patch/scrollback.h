#define TLINE(y) ((y) < term.scr ? term.hist[((y) + term.histi - \
                     term.scr + HISTSIZE + 1) % HISTSIZE] : \
                     term.line[(y) - term.scr])

#define TLINE_HIST(y)           ((y) <= HISTSIZE-term.row+2 ? term.hist[(y)] : term.line[(y-HISTSIZE+term.row-3)])

void kscrolldown(const Arg *);
void kscrollup(const Arg *);

typedef struct {
	 uint b;
	 uint mask;
	 void (*func)(const Arg *);
	 const Arg arg;
} MouseKey;

extern MouseKey mkeys[];

int tisaltscr(void);
