# libft

42 project: basic library inspired by the standard C library

## printf bonuses
### coloration
example : ``ft_printf("%kI'm red%k %d is blue\n", FMT_RED, FMT_BLUE, 42);``

### binary support
exemple : ``ft_printf("%b\n", 42);``
outputs ``101010``

### \* flag support

### alternative functions
sprintf
asprintf
dprintf
vprintf
vsprintf
vasprintf
vdprintf

### multi-ordering flags

## TODO
- strsplit utiliser strchr
- strsplit verifier la valeur de retour de get\_word pour un NULL
- strlcat gerer quon accede pas a la derniere case du buffer s1 quand i == size
- Think of a makefile that can subcompile libft
- getnextline leaks
- Fix getnextline for an empty line
- Implement generic hash table

### lists
CHOISIR ENTRE
-- Implementation C++ avec des pointeurs de fonction constructeur et destructeur en param
-- Implementation avec des pointeurs

### Gerer les exceptions
