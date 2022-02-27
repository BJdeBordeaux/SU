# Rapport de TME4
### par LI Junji 28610187 && Mohamed BABAALI 28601465
<hr>

1. fait. Avec affichage:
    ```shell
        arbre 3
        ├─arbre 3
        │   ├─arbre 3
        │   │   ├─arbre 3
        │   │   └─arbre 3
        │   └─arbre 3
        │       ├─arbre 3
        │       └─arbre 3
        └─arbre 3
            ├─arbre 3
            │   ├─arbre 3
            │   └─arbre 3
            └─arbre 3
                ├─arbre 3
                └─arbre 3
    ```

1. fait. Avec l'affichage. On peut faire des `./minishell` imbriqués.
    ```shell
            $ ./minishell
            Bienvenu à minishell
            ./minishell     # niveau 1
            Bienvenu à minishell
            ./minishell &   # niveau 2
            Bienvenu à minishell
            ls -la          # niveau 2
            total 68
            drwxrwxr-x  2 bj bj  4096 févr. 27 18:25 .
            drwxrwxr-x 10 bj bj  4096 févr. 23 18:43 ..
            -rwxrwxr-x  1 bj bj 20072 févr. 23 17:39 arbre
            -rw-rw-r--  1 bj bj   791 févr. 23 17:39 arbre.c
            -rw-rw-r--  1 bj bj   217 févr. 23 16:44 Makefile
            -rwxrwxr-x  1 bj bj 21776 févr. 27 18:25 minishell
            -rw-rw-r--  1 bj bj  1504 févr. 27 18:25 minishell.c
            -rw-rw-r--  1 bj bj  1427 févr. 27 18:19 README.md
            quit            # niveau 2
            Goodbye!
            utime: 0.000000s
            stime: 0.004317s       # résumé pour commande "./minishell" (niveau 1)
            ls -la          # niveau 1
            total 68
            drwxrwxr-x  2 bj bj  4096 févr. 27 18:25 .
            drwxrwxr-x 10 bj bj  4096 févr. 23 18:43 ..
            -rwxrwxr-x  1 bj bj 20072 févr. 23 17:39 arbre
            -rw-rw-r--  1 bj bj   791 févr. 23 17:39 arbre.c
            -rw-rw-r--  1 bj bj   217 févr. 23 16:44 Makefile
            -rwxrwxr-x  1 bj bj 21776 févr. 27 18:25 minishell
            -rw-rw-r--  1 bj bj  1504 févr. 27 18:25 minishell.c
            -rw-rw-r--  1 bj bj  1427 févr. 27 18:19 README.md
            utime: 0.000000s
            stime: 0.003112s        # résumé pour commande "ls -la" (niveau 1)
            quit            # niveau 1
            Goodbye!
    ```