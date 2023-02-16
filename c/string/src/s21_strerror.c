#include "s21_string.h"

/* Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке.
   Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux. Описания ошибок есть
   в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив.
*/
#if defined (__APPLE__) && defined (__MACH__)
    #define UNDEF           0        /* Undefined error: 0 */
    #define EPERM           1        /* Operation not permitted */
    #define ENOENT          2        /* No such file or directory */
    #define ESRCH           3        /* No such process */
    #define EINTR           4        /* Interrupted system call */
    #define EIO             5        /* Input/output error */
    #define ENXIO           6        /* Device not configured */
    #define E2BIG           7        /* Argument list too long */
    #define ENOEXEC         8        /* Exec format error */
    #define EBADF           9        /* Bad file descriptor */
    #define ECHILD          10       /* No child processes */
    #define EDEADLK         11       /* Resource deadlock avoided */
    #define ENOMEM          12       /* Cannot allocate memory */
    #define EACCES          13       /* Permission denied */
    #define EFAULT          14       /* Bad address */
    #define ENOTBLK         15       /* Block device required */
    #define EBUSY           16       /* Resource busy */
    #define EEXIST          17       /* File exists */
    #define EXDEV           18       /* Cross-device link */
    #define ENODEV          19       /* Operation not supported by device */
    #define ENOTDIR         20       /* Not a directory */
    #define EISDIR          21       /* Is a directory */
    #define EINVAL          22       /* Invalid argument */
    #define ENFILE          23       /* Too many open files in system */
    #define EMFILE          24       /* Too many open files */
    #define ENOTTY          25       /* Inappropriate ioctl for device */
    #define ETXTBSY         26       /* Text file busy */
    #define EFBIG           27       /* File too large */
    #define ENOSPC          28       /* No space left on device */
    #define ESPIPE          29       /* Illegal seek */
    #define EROFS           30       /* Read-only file system */
    #define EMLINK          31       /* Too many links */
    #define EPIPE           32       /* Broken pipe */
    #define EDOM            33       /* Numerical argument out of domain */
    #define ERANGE          34       /* Result too large */
    #define EAGAIN          35       /* Resource temporarily unavailable */
    #define EINPROGRESS     36       /* Operation now in progress */
    #define EALREADY        37       /* Operation already in progress */
    #define ENOTSOCK        38       /* Socket operation on non-socket */
    #define EDESTADDRREQ    39       /* Destination address required */
    #define EMSGSIZE        40       /* Message too long */
    #define EPROTOTYPE      41       /* Protocol wrong type for socket */
    #define ENOPROTOOPT     42       /* Protocol not available */
    #define EPROTONOSUPPORT 43       /* Protocol not supported */
    #define ESOCKTNOSUPPORT 44       /* Socket type not supported */
    #define ENOTSUP         45       /* Operation not supported */
    #define EPFNOSUPPORT    46       /* Protocol family not supported */
    #define EAFNOSUPPORT    47       /* Address family not supported by protocol family */
    #define EADDRINUSE      48       /* Address already in use */
    #define EADDRNOTAVAIL   49       /* Can't assign requested address */
    #define ENETDOWN        50       /* Network is down */
    #define ENETUNREACH     51       /* Network is unreachable */
    #define ENETRESET       52       /* Network dropped connection on reset */
    #define ECONNABORTED    53       /* Software caused connection abort */
    #define ECONNRESET      54       /* Connection reset by peer */
    #define ENOBUFS         55       /* No buffer space available */
    #define EISCONN         56       /* Socket is already connected */
    #define ENOTCONN        57       /* Socket is not connected */
    #define ESHUTDOWN       58       /* Can't send after socket shutdown */
    #define ETOOMANYREFS    59       /* Too many references: can't splice */
    #define ETIMEDOUT       60       /* Operation timed out */
    #define ECONNREFUSED    61       /* Connection refused */
    #define ELOOP           62       /* Too many levels of symbolic links */
    #define ENAMETOOLONG    63       /* File name too long */
    #define EHOSTDOWN       64       /* Host is down */
    #define EHOSTUNREACH    65       /* No route to host */
    #define ENOTEMPTY       66       /* Directory not empty */
    #define EPROCLIM        67       /* Too many processes */
    #define EUSERS          68       /* Too many users */
    #define EDQUOT          69       /* Disc quota exceeded */
    #define ESTALE          70       /* Stale NFS file handle */
    #define EREMOTE         71       /* Too many levels of remote in path */
    #define EBADRPC         72       /* RPC struct is bad */
    #define ERPCMISMATCH    73       /* RPC version wrong */
    #define EPROGUNAVAIL    74       /* RPC prog. not avail */
    #define EPROGMISMATCH   75       /* Program version wrong */
    #define EPROCUNAVAIL    76       /* Bad procedure for program */
    #define ENOLCK          77       /* No locks available */
    #define ENOSYS          78       /* Function not implemented */
    #define EFTYPE          79       /* Inappropriate file type or format */
    #define EAUTH           80       /* Authentication error */
    #define ENEEDAUTH       81       /* Need authenticator */
    #define EPWROFF         82       /* Device power is off */
    #define EDEVERR         83       /* Device error */
    #define EOVERFLOW       84       /* Value too large to be stored in data type */
    #define EBADEXEC        85       /* Bad executable (or shared library) */
    #define EBADARCH        86       /* Bad CPU type in executable */
    #define ESHLIBVERS      87       /* Shared library version mismatch */
    #define EBADMACHO       88       /* Malformed Mach-o file */
    #define ECANCELED       89       /* Operation canceled */
    #define EIDRM           90       /* Identifier removed */
    #define ENOMSG          91       /* No message of desired type */
    #define EILSEQ          92       /* Illegal byte sequence */
    #define ENOATTR         93       /* Attribute not found */
    #define EBADMSG         94       /* Bad message */
    #define EMULTIHOP       95       /* EMULTIHOP (Reserved)*/
    #define ENODATA         96       /* No message available */
    #define ENOLINK         97       /* Reserved */
    #define ENOSR           98       /* No STREAM resources */
    #define ENOSTR          99       /* Not a STREAM */
    #define EPROTO          100      /* Protocol error */
    #define ETIME           101      /* STREAM ioctl timeout */
    #define EOPNOTSUPP      102      /* Operation not supported on socket */
    #define ENOPOLICY       103      /* Policy not found */
    #define ENOTRECOVERABLE 104      /* State not recoverable */
    #define EOWNERDEAD      105      /* Previous owner died */
    #define EQFULL          106      /* Interface output queue is full */
#else
    #define EPERM           1        /* Operation not permitted */
    #define ENOENT          2        /* No such file or directory */
    #define ESRCH           3        /* No such process */
    #define EINTR           4        /* Interrupted system call */
    #define EIO             5        /* Input/output error */
    #define ENXIO           6        /* No such device or address */
    #define E2BIG           7        /* Argument list too long */
    #define ENOEXEC         8        /* Exec format error */
    #define EBADF           9        /* Bad file descriptor */
    #define ECHILD          10       /* No child processes */
    #define EAGAIN          11       /* Resource temporarily unavailable */
    #define ENOMEM          12       /* Cannot allocate memory */
    #define EACCES          13       /* Permission denied */
    #define EFAULT          14       /* Bad address */
    #define ENOTBLK         15       /* Block device required */
    #define EBUSY           16       /* Device or resource busy*/
    #define EEXIST          17       /* File exists */
    #define EXDEV           18       /* Invalid cross-device link */
    #define ENODEV          19       /* No such device */
    #define ENOTDIR         20       /* Not a directory */
    #define EISDIR          21       /* Is a directory */
    #define EINVAL          22       /* Invalid argument */
    #define ENFILE          23       /* Too many open files in system */
    #define EMFILE          24       /* Too many open files */
    #define ENOTTY          25       /* Not a typewriter !!!!*/
    #define ETXTBSY         26       /* Text file busy */
    #define EFBIG           27       /* File too large */
    #define ENOSPC          28       /* No space left on device */
    #define ESPIPE          29       /* Illegal seek */
    #define EROFS           30       /* Read-only file system */
    #define EMLINK          31       /* Too many links */
    #define EPIPE           32       /* Broken pipe */
    #define EDOM            33       /* Numerical argument out of domain */
    #define ERANGE          34       /* Numerical result out of range */
    #define EDEADLK         35       /* Resource deadlock avoided */
    #define ENAMETOOLONG    36       /* File name too long */
    #define ENOLCK          37       /* No locks available */
    #define ENOSYS          38       /* Function not implemented */
    #define ENOTEMPTY       39       /* Directory not empty */
    #define ELOOP           40       /* Too many levels of symbolic links */
    #define ENOMSG          42       /* No message of desired type */
    #define EIDRM           43       /* Identifier removeds */
    #define ECHRNG          44       /* Channel number out of range */
    #define EL2NSYNC        45       /* Level 2 not synchronized */
    #define EL3HLT          46       /* Level 3 halted */
    #define EL3RST          47       /* Level 3 reset */
    #define ELNRNG          48       /* Link number out of range */
    #define EUNATCH         49       /* Protocol driver not attached */
    #define NOCSI           50       /* No CSI structure available */
    #define EL2HLT          51       /* Level 2 halted */
    #define EBADE           52       /* Invalid exchange */
    #define EBADR           53       /* Invalid request descriptor */
    #define EXFULL          54       /* Exchange full */
    #define ENOANO          55       /* No anode */
    #define EBADRQC         56       /* Invalid request code */
    #define EBADSLT         57       /* Invalid slot */
    #define EBFONT          59       /* Bad font file format */
    #define ENOSTR          60       /* Device not a stream */
    #define ENODATA         61       /* No data available */
    #define ETIME           62       /* Timer expired */
    #define ENOSR           63       /* Out of streams resources */
    #define ENONET          64       /* Machine is not on the network */
    #define ENOPKG          65       /* Package not installed */
    #define EREMOTE         66       /* Object is remote */
    #define ENOLINK         67       /* Link has been severed */
    #define EADV            68       /* Advertise error */
    #define ESRMNT          69       /* Srmount error */
    #define ECOMM           70       /* Communication error on send */
    #define EPROTO          71       /* Protocol error */
    #define EMULTIHOP       72       /* Multihop attempted */
    #define EDOTDOT         73       /* RFS specific error */
    #define EBADMSG         74       /* Not a data message !!!*/
    #define EOVERFLOW       75       /* Value too large for defined data type */
    #define ENOTUNIQ        76       /* Name not unique on network */
    #define EBADFD          77       /* File descriptor in bad state */
    #define EREMCHG         78       /* Remote address changed */
    #define ELIBACC         79       /* Can not access a needed shared library */
    #define ELIBBAD         80       /* Accessing a corrupted shared library */
    #define ELIBSCN         81       /* .lib section in a.out corrupted */
    #define ELIBMAX         82       /* Attempting to link in too many shared libraries */
    #define ELIBEXEC        83       /* Cannot exec a shared library directly */
    #define EILSEQ          84       /* Illegal byte sequence !!!*/
    #define ERESTART        85       /* Interrupted system call should be restarted */
    #define ESTRPIPE        86       /* Streams pipe error */
    #define EUSERS          87       /* Too many users */
    #define ENOTSOCK        88       /* Socket operation on non-socket */
    #define EDESTADDRREQ    89       /* Destination address required */
    #define EMSGSIZE        90       /* Message too long */
    #define EPROTOTYPE      91       /* Protocol wrong type for socket */
    #define ENOPROTOOPT     92       /* Protocol not available */
    #define EPROTONOSUPPORT 93       /* Protocol not supported */
    #define ESOCKTNOSUPPORT 94       /* Socket type not supported */
    #define EOPNOTSUPP      95       /* Operation not supported on transport endpoint */
    #define EPFNOSUPPORT    96       /* Protocol family not supported */
    #define EAFNOSUPPORT    97       /* Address family not supported by protocol */
    #define EADDRINUSE      98       /* Address already in use */
    #define EADDRNOTAVAIL   99       /* Cannot assign requested address */
    #define ENETDOWN        100      /* Network is down */
    #define ENETUNREACH     101      /* Network is unreachable */
    #define ENETRESET       102      /* Network dropped connection because of reset !!*/
    #define ECONNABORTED    103      /* Software caused connection abort */
    #define ECONNRESET      104      /* Connection reset by peer */
    #define ENOBUFS         105      /* No buffer space available */
    #define EISCONN         106      /* Transport endpoint is already connected */
    #define ENOTCONN        107      /* Transport endpoint is not connected */
    #define ESHUTDOWN       108      /* Cannot send after transport endpoint shutdown */
    #define ETOOMANYREFS    109      /* Too many references: cannot splice */
    #define ETIMEDOUT       110      /* Connection timed out */
    #define ECONNREFUSED    111      /* Connection refused */
    #define EHOSTDOWN       112      /* Host is down */
    #define EHOSTUNREACH    113      /* No route to host */
    #define EEALREADY       114      /* Operation already in progress */
    #define EINPROGRESS     115      /* Operation now in progress */
    #define ESTALE          116      /* Stale NFS file handle */
    #define EUCLEAN         117      /* Structure needs cleaning */
    #define ENOTNAM         118      /* Not a XENIX named type file */
    #define ENAVAIL         119      /* No XENIX semaphores available */
    #define EISNAM          120      /* Is a named type file */
    #define EREMOTEIO       121      /* Remote I/O error */
    #define EDQUOT          122      /* Quota exceeded !!!*/
    #define ENOMEDIUM       123      /* No medium found */
    #define EMEDIUMTYPE     124      /* Wrong medium type */
    #define ECANCELED       125      /* Operation Canceled*/
    #define ENOKEY          126      /* Required key not available */
    #define EKEYEXPIRED     127      /* Key has expired */
    #define EKEYREVOKED     128      /* Key has been revoked */
    #define EKEYREJECTED    129      /* Key was rejected by service */
    #define EOWNERDEAD      130      /* Owner died */
    #define ENOTRECOVERABLE 131      /* State not recoverable */
    #define ERFKILL         132      /* Operation not possible due to RF-kill */
    #define EHWPOISON       133      /* Memory page has hardware error */
#endif
#if defined (__APPLE__) && defined(__MACH__)
    #define UNKNOWN "Unknown error: "
#else
    #define UNKNOWN "Unknown error "
#endif
static char buf[40] = UNKNOWN;

char *s21_strerror(int errnum) {
    #define CHECK(n, s) do { \
        if (errnum == (n))   \
            return (s);      \
    } while (0)
    unsigned int num = errnum;
    char *p, *t;
    char tmp[40];

    #if defined (__APPLE__) && defined(__MACH__)
        CHECK(UNDEF, "Undefined error: 0");
        CHECK(EPERM, "Operation not permitted");
        CHECK(ENOENT, "No such file or directory");
        CHECK(ESRCH, "No such process");
        CHECK(EINTR, "Interrupted system call");
        CHECK(EIO, "Input/output error");
        CHECK(ENXIO, "Device not configured");
        CHECK(E2BIG, "Argument list too long");
        CHECK(ENOEXEC, "Exec format error");
        CHECK(EBADF, "Bad file descriptor");
        CHECK(ECHILD, "No child processes");
        CHECK(EDEADLK, "Resource deadlock avoided");
        CHECK(ENOMEM, "Cannot allocate memory");
        CHECK(EACCES, "Permission denied");
        CHECK(EFAULT, "Bad address");
        CHECK(ENOTBLK, "Block device required");
        CHECK(EBUSY, "Resource busy");
        CHECK(EEXIST, "File exists");
        CHECK(EXDEV, "Cross-device link");
        CHECK(ENODEV, "Operation not supported by device");
        CHECK(ENOTDIR, "Not a directory");
        CHECK(EISDIR, "Is a directory");
        CHECK(EINVAL, "Invalid argument");
        CHECK(ENFILE, "Too many open files in system");
        CHECK(EMFILE, "Too many open files");
        CHECK(ENOTTY, "Inappropriate ioctl for device");
        CHECK(ETXTBSY, "Text file busy");
        CHECK(EFBIG, "File too large");
        CHECK(ENOSPC, "No space left on device");
        CHECK(ESPIPE, "Illegal seek");
        CHECK(EROFS, "Read-only file system");
        CHECK(EMLINK, "Too many links");
        CHECK(EPIPE, "Broken pipe");
        CHECK(EDOM, "Numerical argument out of domain");
        CHECK(ERANGE, "Result too large");
        CHECK(EAGAIN, "Resource temporarily unavailable");
        CHECK(EINPROGRESS, "Operation now in progress");
        CHECK(EALREADY, "Operation already in progress");
        CHECK(ENOTSOCK, "Socket operation on non-socket");
        CHECK(EDESTADDRREQ, "Destination address required");
        CHECK(EMSGSIZE, "Message too long");
        CHECK(EPROTOTYPE, "Protocol wrong type for socket");
        CHECK(ENOPROTOOPT, "Protocol not available");
        CHECK(EPROTONOSUPPORT, "Protocol not supported");
        CHECK(ESOCKTNOSUPPORT, "Socket type not supported");
        CHECK(ENOTSUP, "Operation not supported");
        CHECK(EPFNOSUPPORT, "Protocol family not supported");
        CHECK(EAFNOSUPPORT, "Address family not supported by protocol family");
        CHECK(EADDRINUSE, "Address already in use");
        CHECK(EADDRNOTAVAIL, "Can't assign requested address");
        CHECK(ENETDOWN, "Network is down");
        CHECK(ENETUNREACH, "Network is unreachable");
        CHECK(ENETRESET, "Network dropped connection on reset");
        CHECK(ECONNABORTED, "Software caused connection abort");
        CHECK(ECONNRESET, "Connection reset by peer");
        CHECK(ENOBUFS, "No buffer space available");
        CHECK(EISCONN, "Socket is already connected");
        CHECK(ENOTCONN, "Socket is not connected");
        CHECK(ESHUTDOWN, "Can't send after socket shutdown");
        CHECK(ETOOMANYREFS, "Too many references: can't splice");
        CHECK(ETIMEDOUT, "Operation timed out");
        CHECK(ECONNREFUSED, "Connection refused");
        CHECK(ELOOP, "Too many levels of symbolic links");
        CHECK(ENAMETOOLONG, "File name too long");
        CHECK(EHOSTDOWN, "Host is down");
        CHECK(EHOSTUNREACH, "No route to host");
        CHECK(ENOTEMPTY, "Directory not empty");
        CHECK(EPROCLIM, "Too many processes");
        CHECK(EUSERS, "Too many users");
        CHECK(EDQUOT, "Disc quota exceeded");
        CHECK(ESTALE, "Stale NFS file handle");
        CHECK(EREMOTE, "Too many levels of remote in path");
        CHECK(EBADRPC, "RPC struct is bad");
        CHECK(ERPCMISMATCH, "RPC version wrong");
        CHECK(EPROGUNAVAIL, "RPC prog. not avail");
        CHECK(EPROGMISMATCH, "Program version wrong");
        CHECK(EPROCUNAVAIL, "Bad procedure for program");
        CHECK(ENOLCK, "No locks available");
        CHECK(ENOSYS, "Function not implemented");
        CHECK(EFTYPE, "Inappropriate file type or format");
        CHECK(EAUTH, "Authentication error");
        CHECK(ENEEDAUTH, "Need authenticator");
        CHECK(EPWROFF, "Device power is off");
        CHECK(EDEVERR, "Device error");
        CHECK(EOVERFLOW, "Value too large to be stored in data type");
        CHECK(EBADEXEC, "Bad executable (or shared library)");
        CHECK(EBADARCH, "Bad CPU type in executable");
        CHECK(ESHLIBVERS, "Shared library version mismatch");
        CHECK(EBADMACHO, "Malformed Mach-o file");
        CHECK(ECANCELED, "Operation canceled");
        CHECK(EIDRM, "Identifier removed");
        CHECK(ENOMSG, "No message of desired type");
        CHECK(EILSEQ, "Illegal byte sequence");
        CHECK(ENOATTR, "Attribute not found");
        CHECK(EBADMSG, "Bad message");
        CHECK(EMULTIHOP, "EMULTIHOP (Reserved)");
        CHECK(ENODATA, "No message available on STREAM");
        CHECK(ENOLINK, "ENOLINK (Reserved)");
        CHECK(ENOSR, "No STREAM resources");
        CHECK(ENOSTR, "Not a STREAM");
        CHECK(EPROTO, "Protocol error");
        CHECK(ETIME, "STREAM ioctl timeout");
        CHECK(EOPNOTSUPP, "Operation not supported on socket");
        CHECK(ENOPOLICY, "Policy not found");
        CHECK(ENOTRECOVERABLE, "State not recoverable");
        CHECK(EOWNERDEAD, "Previous owner died");
        CHECK(EQFULL, "Interface output queue is full");
    #else
        CHECK(EPERM, "Operation not permitted");
        CHECK(ENOENT, "No such file or directory");
        CHECK(ESRCH, "No such process");
        CHECK(EINTR, "Interrupted system call");
        CHECK(EIO, "Input/output error");
        CHECK(ENXIO, "No such device or address");
        CHECK(E2BIG, "Argument list too long");
        CHECK(ENOEXEC, "Exec format error");
        CHECK(EBADF, "Bad file descriptor");
        CHECK(ECHILD, "No child processes");
        CHECK(EAGAIN, "Resource temporarily unavailable");
        CHECK(ENOMEM, "Cannot allocate memory");
        CHECK(EACCES, "Permission denied");
        CHECK(EFAULT, "Bad address");
        CHECK(ENOTBLK, "Block device required");
        CHECK(EBUSY, "Device or resource busy");
        CHECK(EEXIST, "File exists");
        CHECK(EXDEV, "Invalid cross-device link");
        CHECK(ENODEV, "No such device");
        CHECK(ENOTDIR, "Not a directory");
        CHECK(EISDIR, "Is a directory");
        CHECK(EINVAL, "Invalid argument");
        CHECK(ENFILE, "Too many open files in system");
        CHECK(EMFILE, "Too many open files");
        CHECK(ENOTTY, "Not a typewriter");
        CHECK(ETXTBSY, "Text file busy");
        CHECK(EFBIG, "File too large");
        CHECK(ENOSPC, "No space left on device");
        CHECK(ESPIPE, "Illegal seek");
        CHECK(EROFS, "Read-only file system");
        CHECK(EMLINK, "Too many links");
        CHECK(EPIPE, "Broken pipe");
        CHECK(EDOM, "Numerical argument out of domain");
        CHECK(ERANGE, "Numerical result out of range");
        CHECK(EDEADLK, "Resource deadlock avoided");
        CHECK(ENAMETOOLONG, "File name too long");
        CHECK(ENOLCK, "No locks available");
        CHECK(ENOSYS, "Function not implemented");
        CHECK(ENOTEMPTY, "Directory not empty");
        CHECK(ELOOP, "Too many levels of symbolic links");
        CHECK(ENOMSG, "No message of desired type");
        CHECK(EIDRM, "Identifier removed");
        CHECK(ECHRNG, "Channel number out of range");
        CHECK(EL2NSYNC, "Level 2 not synchronized");
        CHECK(EL3HLT, "Level 3 halted");
        CHECK(EL3RST, "Level 3 reset");
        CHECK(ELNRNG, "Link number out of range");
        CHECK(EUNATCH, "Protocol driver not attached");
        CHECK(NOCSI, "No CSI structure available");
        CHECK(EL2HLT, "Level 2 halted");
        CHECK(EBADE, "Invalid exchange");
        CHECK(EBADR, "Invalid request descriptor");
        CHECK(EXFULL, "Exchange full");
        CHECK(ENOANO, "No anode");
        CHECK(EBADRQC, "Invalid request code");
        CHECK(EBADSLT, "Invalid slot");
        CHECK(EBFONT, "Bad font file format");
        CHECK(ENOSTR, "Device not a stream");
        CHECK(ENODATA, "No data available");
        CHECK(ETIME, "Timer expired");
        CHECK(ENOSR, "Out of streams resources");
        CHECK(ENONET, "Machine is not on the network");
        CHECK(ENOPKG, "Package not installed");
        CHECK(EREMOTE, "Object is remote");
        CHECK(ENOLINK, "Link has been severed");
        CHECK(EADV, "Advertise error");
        CHECK(ESRMNT, "Srmount error");
        CHECK(ECOMM, "Communication error on send");
        CHECK(EPROTO, "Protocol error");
        CHECK(EMULTIHOP, "Multihop attempted");
        CHECK(EDOTDOT, "RFS specific error");
        CHECK(EBADMSG, "Not a data message");
        CHECK(EOVERFLOW, "Value too large for defined data type");
        CHECK(ENOTUNIQ, "Name not unique on network");
        CHECK(EBADFD, "File descriptor in bad state");
        CHECK(EREMCHG, "Remote address changed");
        CHECK(ELIBACC, "Can not access a needed shared library");
        CHECK(ELIBBAD, "Accessing a corrupted shared library");
        CHECK(ELIBSCN, ".lib section in a.out corrupted");
        CHECK(ELIBMAX, "Attempting to link in too many shared libraries");
        CHECK(ELIBEXEC, "Cannot exec a shared library directly");
        CHECK(EILSEQ, "Illegal byte sequence");
        CHECK(ERESTART, "Interrupted system call should be restarted");
        CHECK(ESTRPIPE, "Streams pipe error");
        CHECK(EUSERS, "Too many users");
        CHECK(ENOTSOCK, "Socket operation on non-socket");
        CHECK(EDESTADDRREQ, "Destination address required");
        CHECK(EMSGSIZE, "Message too long");
        CHECK(EPROTOTYPE, "Protocol wrong type for socket");
        CHECK(ENOPROTOOPT, "Protocol not available");
        CHECK(EPROTONOSUPPORT, "Protocol not supported");
        CHECK(ESOCKTNOSUPPORT, "Socket type not supported");
        CHECK(EOPNOTSUPP, "Operation not supported on transport endpoint");
        CHECK(EPFNOSUPPORT, "Protocol family not supported");
        CHECK(EAFNOSUPPORT, "Address family not supported by protocol");
        CHECK(EADDRINUSE, "Address already in use");
        CHECK(EADDRNOTAVAIL, "Cannot assign requested address");
        CHECK(ENETDOWN, "Network is down");
        CHECK(ENETUNREACH, "Network is unreachable");
        CHECK(ENETRESET, "Network dropped connection because of reset");
        CHECK(ECONNABORTED, "Software caused connection abort");
        CHECK(ECONNRESET, "Connection reset by peer");
        CHECK(ENOBUFS, "No buffer space available");
        CHECK(EISCONN, "Transport endpoint is already connected");
        CHECK(ENOTCONN, "Transport endpoint is not connected");
        CHECK(ESHUTDOWN, "Cannot send after transport endpoint shutdown");
        CHECK(ETOOMANYREFS, "Too many references: cannot splice");
        CHECK(ETIMEDOUT, "Connection timed out");
        CHECK(ECONNREFUSED, "Connection refused");
        CHECK(EHOSTDOWN, "Host is down");
        CHECK(EHOSTUNREACH, "No route to host");
        CHECK(EEALREADY, "Operation already in progress");
        CHECK(EINPROGRESS, "Operation now in progress");
        CHECK(ESTALE, "Stale NFS file handle");
        CHECK(EUCLEAN, "Structure needs cleaning");
        CHECK(ENOTNAM, "Not a XENIX named type file");
        CHECK(ENAVAIL, "No XENIX semaphores available");
        CHECK(EISNAM, "Is a named type file");
        CHECK(EREMOTEIO, "Remote I/O error");
        CHECK(EDQUOT, "Quota exceeded");
        CHECK(ENOMEDIUM, "No medium found");
        CHECK(EMEDIUMTYPE, "Wrong medium type");
        CHECK(ECANCELED, "Operation Canceled");
        CHECK(ENOKEY, "Required key not available");
        CHECK(EKEYEXPIRED, "Key has expired");
        CHECK(EKEYREVOKED, "Key has been revoked");
        CHECK(EKEYREJECTED, "Key was rejected by service");
        CHECK(EOWNERDEAD, "Owner died");
        CHECK(ENOTRECOVERABLE, "State not recoverable");
        CHECK(ERFKILL, "Operation not possible due to RF-kill");
        CHECK(EHWPOISON, "Memory page has hardware error");
    #endif
    t = tmp;
    do {
        *t++ = "0123456789"[num % 10];
    } while (num /= 10);
    for (p = buf + sizeof(UNKNOWN) - 1;;) {
        *p++ = *--t;
        if (t <= tmp)
            break;
    }
    return(buf);
}
