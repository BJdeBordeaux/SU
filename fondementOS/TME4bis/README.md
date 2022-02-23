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
        % ./minishell
        Bienvenu à minishell
        ls -la
        total 64
        drwxrwxr-x  2 bj bj  4096 févr. 23 18:38 .
        drwxrwxr-x 10 bj bj  4096 févr. 23 16:16 ..
        -rwxrwxr-x  1 bj bj 20072 févr. 23 17:39 arbre
        -rw-rw-r--  1 bj bj   791 févr. 23 17:39 arbre.c
        -rw-rw-r--  1 bj bj   217 févr. 23 16:44 Makefile
        -rwxrwxr-x  1 bj bj 20320 févr. 23 18:38 minishell
        -rw-rw-r--  1 bj bj  1196 févr. 23 18:38 minishell.c
        -rw-rw-r--  1 bj bj  1621 févr. 23 18:22 README.md
        0.00user 0.00system 0:00.00elapsed 100%CPU (0avgtext+0avgdata 3196maxresident)k
        0inputs+0outputs (0major+153minor)pagefaults 0swaps # pour commande "ls la"
        ./minishell &
        Bienvenu à minishell
        quit
        Goodbye!
        0.00user 0.00system 0:03.27elapsed 0%CPU (0avgtext+0avgdata 1284maxresident)k
        0inputs+0outputs (0major+94minor)pagefaults 0swaps # pour commande "./minishell"
        quit
        Goodbye!
    ```