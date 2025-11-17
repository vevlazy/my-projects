#include "s21_string.h"

#ifdef __linux__
static char* error_messages[] = {
    "Success",                       // 0
    "Operation not permitted",       // 1 (EPERM)
    "No such file or directory",     // 2 (ENOENT)
    "No such process",               // 3 (ESRCH)
    "Interrupted system call",       // 4 (EINTR)
    "Input/output error",            // 5 (EIO)
    "No such device or address",     // 6 (ENXIO)
    "Argument list too long",        // 7 (E2BIG)
    "Exec format error",             // 8 (ENOEXEC)
    "Bad file descriptor",           // 9 (EBADF)
    "No child processes",            // 10 (ECHILD)
    "Resource temporarily unavailable", // 11 (EAGAIN)
    "Cannot allocate memory",        // 12 (ENOMEM)
    "Permission denied",             // 13 (EACCES)
    "Bad address",                   // 14 (EFAULT)
    "Block device required",         // 15 (ENOTBLK)
    "Device or resource busy",       // 16 (EBUSY)
    "File exists",                   // 17 (EEXIST)
    "Invalid cross-device link",     // 18 (EXDEV)
    "No such device",                // 19 (ENODEV)
    "Not a directory",               // 20 (ENOTDIR)
    "Is a directory",                // 21 (EISDIR)
    "Invalid argument",              // 22 (EINVAL)
    "Too many open files in system", // 23 (ENFILE)
    "Too many open files",           // 24 (EMFILE)
    "Inappropriate ioctl for device",// 25 (ENOTTY)
    "Text file busy",                // 26 (ETXTBSY)
    "File too large",                // 27 (EFBIG)
    "No space left on device",       // 28 (ENOSPC)
    "Illegal seek",                  // 29 (ESPIPE)
    "Read-only file system",         // 30 (EROFS)
    "Too many links",                // 31 (EMLINK)
    "Broken pipe",                   // 32 (EPIPE)
    "Numerical argument out of domain", // 33 (EDOM)
    "Numerical result out of range", // 34 (ERANGE)
    "Resource deadlock avoided",     // 35 (EDEADLK)
    "File name too long",            // 36 (ENAMETOOLONG)
    "No locks available",            // 37 (ENOLCK)
    "Function not implemented",      // 38 (ENOSYS)
    "Directory not empty",           // 39 (ENOTEMPTY)
    "Too many levels of symbolic links", // 40 (ELOOP)
    S21_NULL,              // 41 (зарезервированный номер)
    "No message of desired type",    // 42 (ENOMSG)
    "Identifier removed",            // 43 (EIDRM)
    "Channel number out of range",   // 44 (ECHRNG)
    "Level 2 not synchronized",      // 45 (EL2NSYNC)
    "Level 3 halted",                // 46 (EL3HLT)
    "Level 3 reset",                 // 47 (EL3RST)
    "Link number out of range",      // 48 (ELNRNG)
    "Protocol driver not attached",  // 49 (EUNATCH)
    "No CSI structure available",    // 50 (ENOCSI)
    "Level 2 halted",                // 51 (EL2HLT)
    "Invalid exchange",              // 52 (EBADE)
    "Invalid request descriptor",    // 53 (EBADR)
    "Exchange full",                 // 54 (EXFULL)
    "No anode",                      // 55 (ENOANO)
    "Invalid request code",          // 56 (EBADRQC)
    "Invalid slot",                  // 57 (EBADSLT)
    S21_NULL,             // 58 (зарезервированный номер)
    "Bad font file format",          // 59 (EBFONT)
    "Device not a stream",           // 60 (ENOSTR)
    "No data available",             // 61 (ENODATA)
    "Timer expired",                 // 62 (ETIME)
    "Out of streams resources",      // 63 (ENOSR)
    "Machine is not on the network", // 64 (ENONET)
    "Package not installed",         // 65 (ENOPKG)
    "Object is remote",              // 66 (EREMOTE)
    "Link has been severed",         // 67 (ENOLINK)
    "Advertise error",               // 68 (EADV)
    "Srmount error",                 // 69 (ESRMNT)
    "Communication error on send",   // 70 (ECOMM)
    "Protocol error",                // 71 (EPROTO)
    "Multihop attempted",            // 72 (EMULTIHOP)
    "RFS specific error",            // 73 (EDOTDOT)
    "Bad message",                   // 74 (EBADMSG)
    "Value too large for defined data type", // 75 (EOVERFLOW)
    "Name not unique on network",    // 76 (ENOTUNIQ)
    "File descriptor in bad state",  // 77 (EBADFD)
    "Remote address changed",        // 78 (EREMCHG)
    "Can not access a needed shared library", // 79 (ELIBACC)
    "Accessing a corrupted shared library", // 80 (ELIBBAD)
    ".lib section in a.out corrupted", // 81 (ELIBSCN)
    "Attempting to link in too many shared libraries", // 82 (ELIBMAX)
    "Cannot exec a shared library directly", // 83 (ELIBEXEC)
    "Invalid or incomplete multibyte or wide character", // 84 (EILSEQ)
    "Interrupted system call should be restarted", // 85 (ERESTART)
    "Streams pipe error",            // 86 (ESTRPIPE)
    "Too many users",                // 87 (EUSERS)
    "Socket operation on non-socket", // 88 (ENOTSOCK)
    "Destination address required",  // 89 (EDESTADDRREQ)
    "Message too long",              // 90 (EMSGSIZE)
    "Protocol wrong type for socket", // 91 (EPROTOTYPE)
    "Protocol not available",        // 92 (ENOPROTOOPT)
    "Protocol not supported",        // 93 (EPROTONOSUPPORT)
    "Socket type not supported",     // 94 (ESOCKTNOSUPPORT)
    "Operation not supported",       // 95 (EOPNOTSUPP)
    "Protocol family not supported", // 96 (EPFNOSUPPORT)
    "Address family not supported by protocol", // 97 (EAFNOSUPPORT)
    "Address already in use",        // 98 (EADDRINUSE)
    "Cannot assign requested address", // 99 (EADDRNOTAVAIL)
    "Network is down",               // 100 (ENETDOWN)
    "Network is unreachable",        // 101 (ENETUNREACH)
    "Network dropped connection on reset", // 102 (ENETRESET)
    "Software caused connection abort", // 103 (ECONNABORTED)
    "Connection reset by peer",      // 104 (ECONNRESET)
    "No buffer space available",     // 105 (ENOBUFS)
    "Transport endpoint is already connected", // 106 (EISCONN)
    "Transport endpoint is not connected", // 107 (ENOTCONN)
    "Cannot send after transport endpoint shutdown", // 108 (ESHUTDOWN)
    "Too many references: cannot splice", // 109 (ETOOMANYREFS)
    "Connection timed out",          // 110 (ETIMEDOUT)
    "Connection refused",            // 111 (ECONNREFUSED)
    "Host is down",                  // 112 (EHOSTDOWN)
    "No route to host",              // 113 (EHOSTUNREACH)
    "Operation already in progress", // 114 (EALREADY)
    "Operation now in progress",     // 115 (EINPROGRESS)
    "Stale file handle",             // 116 (ESTALE)
    "Structure needs cleaning",      // 117 (EUCLEAN)
    "Not a XENIX named type file",   // 118 (ENOTNAM)
    "No XENIX semaphores available", // 119 (ENAVAIL)
    "Is a named type file",          // 120 (EISNAM)
    "Remote I/O error",              // 121 (EREMOTEIO)
    "Disk quota exceeded",           // 122 (EDQUOT)
    "No medium found",               // 123 (ENOMEDIUM)
    "Wrong medium type",             // 124 (EMEDIUMTYPE)
    "Operation canceled",            // 125 (ECANCELED)
    "Required key not available",    // 126 (ENOKEY)
    "Key has expired",               // 127 (EKEYEXPIRED)
    "Key has been revoked",          // 128 (EKEYREVOKED)
    "Key was rejected by service",   // 129 (EKEYREJECTED)
    "Owner died",                    // 130 (EOWNERDEAD)
    "State not recoverable",         // 131 (ENOTRECOVERABLE)
    "Operation not possible due to RF-kill", // 132 (ERFKILL)
    "Memory page has hardware error", // 133 (EHWPOISON)
};
#elif defined(__APPLE__)
static char* error_messages[] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"
};
#endif
static char *last = S21_NULL;


void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char *p = (const unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
        if (p[i] == (unsigned char)c) {
            return (void *)(p + i);
        }
    }
    return S21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p1 = (const unsigned char *)str1;
    const unsigned char *p2 = (const unsigned char *)str2;
    for (s21_size_t i = 0; i < n; i++) {
        if (*(p1 + i) != *(p2 + i)) return (*(p1 + i) - *(p2 + i));
    }
    return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *dest1 = (char*)dest;
    const char *str1 = (const char *)src;
    while (n--)
    {
        *dest1 = *str1;
        dest1++;
        str1++;
    }
    return dest;   
}

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *p = (unsigned char *)str;
    for (s21_size_t i = 0; i < n; i++) {
        p[i] = (unsigned char)c;
    }
    return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n){
    s21_size_t len = s21_strlen(dest);
    s21_size_t i=0;
    for (; i < n && src[i]!='\0'; i++)
    {
        dest[len+i]=src[i];
    }
    dest[len+i]='\0';
    return dest;
    
}

char *s21_strchr(const char *str, int c) {
    return s21_memchr(str, c, s21_strlen(str) + 1);
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    return s21_memcmp(str1, str2, n);
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n){
    s21_size_t count = 0;
    for (s21_size_t i = 0; i < n && src[i] != '\0'; i++)
    {
        dest[i]=src[i];
        count++;
    }
    for (s21_size_t i = count; i < n; i++)
    {
        dest[i]='\0';
    }
    return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t i ,j;
    for (i = 0; str1[i] != '\0'; i++)
        for (j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i]==str2[j])return i;
        }
    return i;
}

char* s21_strerror(int errnum) {
    if (errnum < 0 || (s21_size_t)errnum >= sizeof(error_messages) / sizeof(error_messages[0])
                   || !error_messages[errnum]) {
        static char buffer[64];
#ifdef __linux__
        sprintf(buffer, "Unknown error %d", errnum);
#elif defined(__APPLE__)
        sprintf(buffer, "Unknown error: %d", errnum);
#endif
        return buffer;
    }
    return error_messages[errnum];
}

s21_size_t s21_strlen(const char *str) {
    s21_size_t result = 0;
    const unsigned char *p = (const unsigned char *)str;
    for (s21_size_t i = 0; p[i] != '\0'; i++) result++;
    return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *p = (char *)str1;
    s21_size_t str1_len = s21_strlen(str1);
    for (s21_size_t i = 0; i < str1_len; i++) {
        char *result = s21_memchr(str2, str1[i], 1);
        if (result) return p + i;
    }
    return S21_NULL;
}

char *s21_strrchr(const char *str, int c) {
    const char *p = (const char *)str;
    int str_len = s21_strlen(str);
    for (int i = str_len + 1; i >= 0; i--) {
        if (p[i] == c) {
            return (char *)(p + i);
        }
    }
    return S21_NULL;
}

char *s21_strstr(const char *haystack, const char *needle) {
    s21_size_t needle_len = s21_strlen(needle);
    if (needle_len == 0) return (char *)haystack;
    char *p = (char *)haystack;
    s21_size_t haystack_len = s21_strlen(haystack);
    if (needle_len > haystack_len) return S21_NULL;
    for (s21_size_t i = 0; i <= haystack_len - needle_len; i++) {
        if (haystack[i] == needle[0]) {
            if (!s21_memcmp(p + i, needle, needle_len)) {
                return p + i;
            }
        }
    }
    return S21_NULL;
}
char *s21_strtok(char *str,const char *delim){
    char *token;
    if(str != S21_NULL){
        last = str;
    } else if (last == S21_NULL)
    {
        return S21_NULL;
    }
    while (*last != '\0' && s21_strchr(delim, *last) !=S21_NULL)
    {
        ++last;
    }
    if (*last == '\0')
    {
        last= S21_NULL;
        return S21_NULL;
    }
    token = last;
    while (*last != '\0' && s21_strchr(delim,*last)==S21_NULL)
    {
        ++last;
    }
    if (*last!='\0')
    {
        *last = '\0';
        ++last;
    }
    return token;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    while(*format) {
        if (*format == '%') {
            FormatOptions options = {0};
            format++;
            while (*format == '-' || *format == '+' || *format == ' ') {
                switch (*format) {
                case '-':
                    options.flags |= FLAG_MINUS;
                    break;
                case '+':
                    options.flags |= FLAG_PLUS;
                    break;
                case ' ':
                    options.flags |= FLAG_SPACE;
                    break;
                }
                format++;
            }
            if (*format >= '0' && *format <= '9') {
                options.width = 0;
                while (*format >= '0' && *format <= '9') {
                    options.width = options.width * 10 + (*format - '0');
                    format++;
                }
            }
            if (*format == '.') {
                format++;
                options.precision = 0;
                while (*format >= '0' && *format <= '9') {
                    options.precision = options.precision * 10 + (*format - '0');
                    format++;
                }
            }
            if (*format == 'h' || *format == 'l') {
                options.length = *format;
                format++;
            }
            options.specifier = *format;
            format++;
            apply_format(&str, args, options);
        } else {
            *str++ = *format++;
        }
    }
    va_end(args);
    *str = '\0';
    return 0;
}

void apply_format(char **str, va_list args, FormatOptions options) {
    switch (options.specifier) {
        case 'c':
            format_c(str, (char)va_arg(args, int), options);
            break;
        case 'd':
            long num;
            if (options.length == 'l') {
                num = va_arg(args, long);
            } else {
                num = (long)va_arg(args, int);
            }
            format_d(str, num, options);
            break;
        case 'f':
            //format_f(str, va_arg(args, double), options);
            break;
        case 's':
            format_s(str, va_arg(args, char*), options);
            break;
        case 'u':
            format_u(str, va_arg(args, unsigned int), options);
            break;
        case '%':
            *(*str)++ = '%';
            break;
    }
}

void format_c(char **str, char c, FormatOptions options) {
    if (options.width > 1 && !(options.flags & FLAG_MINUS)) {
        for (int i = 0; i < options.width - 1; i++) {
            *(*str)++ = ' ';
        }
    }
    *(*str)++ = c;
    if (options.width > 1 && (options.flags & FLAG_MINUS)) {
        for (int i = 0; i < options.width - 1; i++) {
            *(*str)++ = ' ';
        }
    }
}

void format_d(char **str, long num, FormatOptions options) {
    int is_negative = 0;
    if (num < 0) {
        num = -num;
        is_negative = 1;
    }

    char *number = int_to_str(num);
    int len = s21_strlen(number);

    if (options.precision < len) options.precision = len;

    if (options.width > options.precision && !(options.flags & FLAG_MINUS)) {
        int to_fill = options.width - options.precision;
        if (is_negative || (options.flags & FLAG_PLUS) || (options.flags & FLAG_SPACE)) to_fill--;
        for (int i = 0; i < to_fill; i++) {
            *(*str)++ = ' ';
        }
    }

    if (is_negative) *(*str)++ = '-';
    else if (options.flags & FLAG_PLUS) *(*str)++ = '+';
    else if (options.flags & FLAG_SPACE) *(*str)++ = ' ';

    if (options.precision > len) {
        int to_fill = options.precision - len;
        for (int i = 0; i < to_fill; i++) {
        *(*str)++ = '0';
        }
    }

    char *p = number;
    while (*p) *(*str)++ = *p++;
    free(number);

    if (options.width > options.precision && (options.flags & FLAG_MINUS)) {
        int to_fill = options.width - options.precision;
        if (is_negative || (options.flags & FLAG_PLUS) || (options.flags & FLAG_SPACE)) to_fill--;
        for (int i = 0; i < to_fill; i++) {
            *(*str)++ = ' ';
        }
    }
}
/*
void format_f(char **str, double num, FormatOptions options) {
    long temp = (long)num;
    long temp_to_int = (long)num;
    double temp_f = num - temp;
    int len = 0;
    int len_f=0;
    int is_negative = 0;
    if (num < 0) {
        num = -num;
        is_negative = 1;
    }
    while (temp > 0) {
        len++;
        temp /= 10;
    }
    
    if (!options.precision) options.precision = len;
    if ((options.flags & FLAG_PLUS) || (options.flags & FLAG_SPACE) || is_negative) {
        len++;
    }

    if (options.width > options.precision && !(options.flags & FLAG_MINUS)) {
        int to_fill = options.width - options.precision;
        for (int i = 0; i < to_fill; i++) {
            *(*str)++ = ' ';
        }
    }

    if (options.precision > len) {
        int to_fill = options.precision - len;
        for (int i = 0; i < to_fill; i++) {
        *(*str)++ = '0';
        }
    }

    if (is_negative) *(*str)++ = '-';
    else if (options.flags & FLAG_PLUS) *(*str)++ = '+';
    else if (options.flags & FLAG_SPACE) *(*str)++ = ' ';

    char *number = int_to_str(temp_to_int);
    char *number_f = double_to_str(temp_f);
    while (*number) *(*str)++ = *number++;
    if (number && num != 0) free(number);
    if (number_f && num != 0) free(number_f);

    if (options.width > options.precision && (options.flags & FLAG_MINUS)) {
        int to_fill = options.width - options.precision;
        for (int i = 0; i < to_fill; i++) {
            *(*str)++ = ' ';
        }
    }
}
*/
void format_s(char **str, char *src, FormatOptions options) {
    int len = s21_strlen(src);
    if (options.precision > len) options.precision = len;
    if (!(options.flags & FLAG_MINUS) && options.width > options.precision) {
        for (int i = 0; i < options.width - options.precision; i++) {
            *(*str)++ = ' ';
        }
    }
    for (int i = 0; i < options.precision; i++) {
        *(*str)++ = *src++;
    }
    if ((options.flags & FLAG_MINUS) && options.width > options.precision) {
        for (int i = 0; i < options.width - options.precision; i++) {
            *(*str)++ = ' ';
        }
    }
}

void format_u(char **str, unsigned long int num, FormatOptions options) {
    char *number = int_to_str(num);
    int len = s21_strlen(number);

    if (options.precision < len) options.precision = len;

    if (options.width > options.precision && !(options.flags & FLAG_MINUS)) {
        int to_fill = options.width - options.precision;
        for (int i = 0; i < to_fill; i++) {
            *(*str)++ = ' ';
        }
    }

    if (options.precision > len) {
        int to_fill = options.precision - len;
        for (int i = 0; i < to_fill; i++) {
        *(*str)++ = '0';
        }
    }

    char *p = number;
    while (*p) *(*str)++ = *p++;
    free(number);

    if (options.width > options.precision && (options.flags & FLAG_MINUS)) {
        int to_fill = options.width - options.precision;
        for (int i = 0; i < to_fill; i++) {
            *(*str)++ = ' ';
        }
    }
}

char *int_to_str(long num) {
    char *result = malloc(32 * sizeof(char));
    int j = 0;
    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';   
        return result;
    }
    while (num > 0) {
        result[j] = num % 10 + '0';
        num /= 10;
        j++;
    }
    result[j] = '\0';

    for (int i = 0; i < j / 2; i++) {
        char temp = result[i];
        result[i] = result[j - i - 1];
        result[j - i - 1] = temp;
    }

    return result;
}

char *double_to_str(double num) {
    char *result = malloc(32 * sizeof(char));
    int max_f = 17;
    int count = 0;
    if (num == 0)
    {
        result[0] = '0';
        result[1] = '\0';   
        return result;
    }
    for (int i = 0; i < max_f; i++)
    {
        num*=10;
        int changer = (int)num;
        num-=changer;
        result[count++]='0'+changer;
        if (num==0)break;
    }
    result[count] = '\0';
    return result;
}

//BONUS
void *s21_to_upper(const char *str){
    if(str==S21_NULL){
        return S21_NULL;
    }
    static char result[1024];
    int len = 0;
    while (str[len]!='\0'||len<1024)
    {
        char symbol = str[len];
        if (symbol >= 'a' && symbol <= 'z'){
            result[len] = symbol - 32;
        }else{
            result[len] = symbol;
        }
        len++;
    }
    result[len]='\0';
    return result;
    
}
void *s21_to_lower(const char *str){
    if(str==S21_NULL){
        return S21_NULL;
    }
    static char result[1024];
    int len = 0;
    while (str[len]!='\0'||len<1024)
    {
        char symbol = str[len];
        if (symbol >= 'A' && symbol <= 'Z'){
            result[len] = symbol + 32;
        }else{
            result[len] = symbol;
        }
        len++;
    }
    result[len]='\0';
    return result;
    
}