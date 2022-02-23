# Rapport de TME4
### par LI Junji 28610187 && Mohamed BABAALI 28601465
<hr>

1. Multi-grep simple

1. Multi-grep MAXFILS

1. Multi-grep avec statistiques
    
    fait dans `mgrep.c`
1. Zombie
    1. C'est un processus terminé tant que son père n'a pas pris connaissance de sa terminaison.(wait)

    1. fait dans `zombie.c`
        ```shell
        ./zombie chaine 1 2 3 4 5 6 7
        This is parent process 6488
        child process 6489
        child process 6491
        child process 6493
        child process 6492
        child process 6494
        child process 6495
        3333333 chaine
        ''44444'' chaine
        7777777 chaine
        child process 6490
        555555 chaine
        chaine 11111
        222222 chaine
        666666666  chaine
        *******************************
        (10 seconde...)
        *******************************
        End child process: 6489
        End child process: 6490
        End child process: 6491
        End child process: 6492
        End child process: 6493
        End child process: 6494
        End child process: 6495
        End parent process: 6488
        ```