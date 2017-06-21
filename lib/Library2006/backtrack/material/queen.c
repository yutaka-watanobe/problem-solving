/************************************************************************/
/*      ８クイーン      単純バージョン                                  */
/*                                                                      */
/*      特徴    サイズをとりあえず可変にしただけ                        */
/*              印字抑制 -p 有り                                        */
/*                                                                      */
/*      usage:  queen [-p] [size]                                       */
/*                                                                      */
/************************************************************************/
#include <stdio.h>

#define MAXBOARDSIZE 20
int     boardsize = 8;

int     answercount;
int     printflag;
typedef char Board[MAXBOARDSIZE][MAXBOARDSIZE];
Board   board;

#define QUEEN   'Q'
#define BLANK   '.'

#define TRUE    1
#define FALSE   0

void    initboard( void );
void    copyboard( Board dest, Board sr );
void    rotate( Board dest, Board src );
void    lrmirror( Board dest, Board src );
int     compareboard(  Board b0, Board b1 );
int     isunique( void );
void    setqueen( int x, int y );
void    setblank( int x, int y );
int     ison( int x, int y );
int     isokleft( int x, int y );
int     isokleftup( int x, int y );
int     isokleftdown( int x, int y );
int     isok( int x, int y );
void    tryqueen( int x, int y );
void    foundanswer( void );
void    printboard( Board b);
int     main( int argc, char **argv );

/*----------------------------------------------------------------------*/
/*      チェス盤の初期化                                                */
/*----------------------------------------------------------------------*/
void    initboard( void )
{
        int     x, y;

        for( x=0; x<boardsize; ++x ) {
                for( y=0; y<boardsize; ++y ) {
                        board[x][y] = BLANK;
                }
        }
}

/*----------------------------------------------------------------------*/
/*      チェス盤のコピー                                                */
/*----------------------------------------------------------------------*/
void    copyboard( Board dest, Board src )
{
        int     x, y;

        for( x=0; x<boardsize; ++x )
                for( y=0; y<boardsize; ++y )
                        dest[x][y] = src[x][y];
}

/*----------------------------------------------------------------------*/
/*      盤面上のコマを９０度回転する                                    */
/*----------------------------------------------------------------------*/
void    rotate( Board dest, Board src )
{
        Board   work;           /* to, from が同じ配列でもOK    */
        int     x, y;

        for( x=0; x<boardsize; ++x )
                for( y=0; y<boardsize; ++y )
                        work[y][boardsize-1-x] = src[x][y];

        copyboard( dest, work );
}

/*----------------------------------------------------------------------*/
/*      盤面上のコマを左右反転する                                      */
/*----------------------------------------------------------------------*/
void    lrmirror( Board dest, Board src )
{
        Board   work;           /* to, from が同じ配列でもOK    */
        int     x, y;

        for( x=0; x<boardsize; ++x )
                for( y=0; y<boardsize; ++y )
                        work[boardsize-1-x][y] = src[x][y];

        copyboard( dest, work );
}

/*----------------------------------------------------------------------*/
/*      盤上の状態による大小比較                                        */
/*----------------------------------------------------------------------*/
int     compareboard( Board b0, Board b1 )
{
        int     x, y;

        for( x=0; x<boardsize; ++x ) {
                for( y=0; y<boardsize; ++y ) {
                        if( b0[x][y] == b1[x][y] )
                                 continue;
                        return (b0[x][y] == QUEEN) ? -1 : 1;
                }
        }
        return  0;
}

/*----------------------------------------------------------------------*/
/*      回転・反転などによるユニーク性のチェック                        */
/*----------------------------------------------------------------------*/
int     isunique( void )
{
        Board   work;

        copyboard( work, board );               /* 元のboardはそのまま  */

        rotate( work, work );                   /*  90度回転    */
        if( compareboard( board, work ) > 0 )
                return  FALSE;
                
        rotate( work, work );                   /* 180度回転    */
        if( compareboard( board, work ) > 0 )
                return  FALSE;
                
        rotate( work, work );                   /* 270度回転    */
        if( compareboard( board, work ) > 0 )
                return  FALSE;

        lrmirror( work, board );                /* 左右裏返し   */
        if( compareboard( board, work ) > 0 )
                return  FALSE;

        rotate( work, work );                   /*  90度回転    */
        if( compareboard( board, work ) > 0 )
                return  FALSE;

        rotate( work, work );                   /* 180度回転    */
        if( compareboard( board, work ) > 0 )
                return  FALSE;

        rotate( work, work );                   /* 270度回転    */
        if( compareboard( board, work ) > 0 )
                return  FALSE;

        return  TRUE;
}

/*----------------------------------------------------------------------*/
/*      チェス盤の指定場所にクイーンをセット                            */
/*----------------------------------------------------------------------*/
void    setqueen( int x, int y )
{
        board[x][y] = QUEEN;
}

/*----------------------------------------------------------------------*/
/*      チェス盤の指定場所をブランクにする                              */
/*----------------------------------------------------------------------*/
void    setblank( int x, int y )
{
        board[x][y] = BLANK;
}

/*----------------------------------------------------------------------*/
/*      指定位置(x,y)が盤上かどうかの判定                               */
/*----------------------------------------------------------------------*/
int     ison( int x, int y )
{
        if( x<0 || x>=boardsize )
                return  FALSE;
        if( y<0 || y>=boardsize )
                return  FALSE;

        return  TRUE;
}

/*----------------------------------------------------------------------*/
/*      同じy座標 (←) のところに他のクイーンがないことを確認           */
/*----------------------------------------------------------------------*/
int     isokleft( int x, int y )
{
        int     i;
        int     stat = TRUE;

        for(;;) {
                --x;
                if( ! ison( x, y ) )
                        break;

                if( board[x][y] == QUEEN ) {
                        stat = FALSE;
                        break;
                }
        }

        return stat;
}

/*----------------------------------------------------------------------*/
/*      左上対角線上 (＼) のところに他のクイーンがないことを確認        */
/*----------------------------------------------------------------------*/
int     isokleftup( int x, int y )
{
        int     i;
        int     stat = TRUE;

        for(;;) {
                --x;
                --y;
                if( ! ison( x, y ) )
                        break;

                if( board[x][y] == QUEEN ) {
                        stat = FALSE;
                        break;
                }
        }

        return stat;
}

/*----------------------------------------------------------------------*/
/*      左下対角線上 (／) のところに他のクイーンがないことを確認        */
/*----------------------------------------------------------------------*/
int     isokleftdown( int x, int y )
{
        int     i;
        int     stat = TRUE;

        for(;;) {
                --x;
                ++y;
                if( ! ison( x, y ) )
                        break;

                if( board[x][y] == QUEEN ) {
                        stat = FALSE;
                        break;
                }
        }

        return stat;
}

/*----------------------------------------------------------------------*/
/*      左上対角線上 (＼) のところに他のクイーンがないことを確認        */
/*----------------------------------------------------------------------*/
int     isok( int x, int y )
{
        if( ! isokleft( x, y ) ) {      /* 効き筋(←)にあるので置けない */
                return  FALSE;
        }

        if( ! isokleftup( x, y ) ) {    /* 効き筋(＼)にあるので置けない */
                return  FALSE;
        }

        if( ! isokleftdown( x, y ) ) {  /* 効き筋(／)にあるので置けない */
                return  FALSE;
        }

        return  TRUE;
}

/*----------------------------------------------------------------------*/
/*      チェス盤の指定場所をにクイーンを置けるか調べる                  */
/*----------------------------------------------------------------------*/
void    tryqueen( int x, int y )
{
        int     z;

        if( ! isok( x, y ) )
                return;

        setqueen( x, y );               /* 置いた */

        if( x == boardsize-1 ) {        /* ８個置き終えた */
                foundanswer();
        } else {                        /* 一つ右側について調べる */    
                for( z=0; z<boardsize; ++z ) {
                        tryqueen( x+1, z );
                }
        }

        setblank( x, y );               /* 外した */
}

/*----------------------------------------------------------------------*/
/*      解が見つかった                                                  */
/*----------------------------------------------------------------------*/
void    foundanswer( void )
{
        if( ! isunique() )
                return;

        ++answercount;

        if( printflag ) {
                printf( "Answer %d\n", answercount );
                printboard( board );
        }
}

/*----------------------------------------------------------------------*/
/*      チェス盤のプリント                                              */
/*----------------------------------------------------------------------*/
void    printboard( Board b )
{
        int     x, y;

        for( y=0; y<boardsize; ++y ) {
                for( x=0; x<boardsize; ++x ) {
                        printf( " %c", b[x][y] );
                }
                printf( "\n" );
        }
        printf( "\n" );
}

/*----------------------------------------------------------------------*/
/*      メイン                                                          */
/*----------------------------------------------------------------------*/
int     main( int argc, char **argv )
{
        int     y;

        printflag = TRUE;

        for( ++argv, --argc; argc>0; ++argv, --argc ) {
                if( isdigit( **argv ) ) {
                        boardsize = atoi( *argv );
                        continue;
                }
                if( strcmp(*argv,"-p") == 0 ) {
                        printflag = FALSE;
                }
        }

        answercount = 0;
        initboard();

        for( y=0; y<boardsize; ++y ) {
                tryqueen( 0, y );
        }

        printf( "Total count %d\n", answercount );
}

/************************************************************************/
/*                              End                                     */
/************************************************************************/
