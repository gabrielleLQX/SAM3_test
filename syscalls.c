#include <sys/stat.h>
 
enum {
  UART_FR_RXFE = 0x10,//receive empty
  UART_FR_TXFF = 0x20,//transmit full
  UART0_ADDR = 0x400e0600,
  UART1_ADDR = 0x400e0800,
  SPI_RXFE = 0x1,//receive empty
  SPI_TXFF = 0x2,//transmit full
  SPI_ADDR = 0x40008000,
};
 
#define UART_DR(baseaddr) (*(unsigned int *)(baseaddr))
#define UART_FR(baseaddr) (*(((unsigned int *)(baseaddr))+6))
#define SPI_TDR(baseaddr) (*(((unsigned int *)(baseaddr))+12))
#define SPI_RDR(baseaddr) (*(((unsigned int *)(baseaddr))+8))
#define SPI_SR(baseaddr) (*(((unsigned int *)(baseaddr))+16))



int _close(int file) {
  return 0;
}
 
int _fstat(int file, struct stat *st) {
  st->st_mode = S_IFCHR;
  return 0;
}
 
int _isatty(int file) {
  return 1;
}
 
int _lseek(int file, int ptr, int dir) {
  return 0;
}
 
int _open(const char *name, int flags, int mode) {
return -1;
}
 
int _read(int file, char *ptr, int len) {
  int todo;
  if(len == 0)
    return 0;

  while(UART_FR(UART0_ADDR) & UART_FR_RXFE);
  *ptr++ = UART_DR(UART0_ADDR);
  for(todo = 1; todo < len; todo++) {
    if(UART_FR(UART0_ADDR) & UART_FR_RXFE) { break; }
    *ptr++ = UART_DR(UART0_ADDR);
  } 
  /*
  while(SPI_SR(SPI_ADDR) & SPI_RXFE);
  *ptr++ = SPI_RDR(SPI_ADDR);
  for(todo = 1; todo < len; todo++) {
    if(SPI_SR(SPI_ADDR) & SPI_RXFE) { break; }
    *ptr++ = SPI_RDR(SPI_ADDR);
  }
  */
  return todo;
}
 
static char *heap_end = 0;
caddr_t _sbrk(int incr) {
  extern char __cs3_heap_start; /* Defined by the linker */
  extern char __cs3_heap_end; /* Defined by the linker */
  char *prev_heap_end;
  if (heap_end == 0) {
    heap_end = &__cs3_heap_start;
  }
  prev_heap_end = heap_end;
  if (heap_end + incr > &__cs3_heap_end) {
    /* Heap and stack collision */
    return (caddr_t)0;
  }
  heap_end += incr;
  return (caddr_t) prev_heap_end;
}
 
int _write(int file, char *ptr, int len) {
  int todo;
  for (todo = 0; todo < len; todo++) {
    UART_DR(UART0_ADDR) = *ptr++;
  }
  /*
  for (todo = 0; todo < len; todo++) {
    SPI_TDR(SPI_ADDR) = *ptr++;
  }
  */
  return len;
}
