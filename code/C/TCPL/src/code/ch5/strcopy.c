/* strcpy: copy t to s; array subscript version */
void strcpy_1(char *s, char *t)
{
    int i;
    i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

/* strcpy: copy t to s; pointer version 1 */
void strcpy_2(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy_3(char *s, char *t)
{
    while ((*s++ = *t++) != '\0') {
        ;
    }
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy_4(char *s, char *t)
{
    while (*s++ = *t++) {
        ;
    }
}

