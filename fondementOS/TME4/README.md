# TME2
### PAR Junji LI && Diego Arbulu
<hr>

1. Multi-grep simple
    1. Voici les affichages poour `time`
        ```shell
        shell  0,28s user 0,11s system 2% cpu 19,293 total
        children  0,15s user 0,12s system 1% cpu 19,293 total
        ````
        `sleep 5` bloque le terminale pendant 5 secondes
        `time sleep 5` donne l'affichage suivant:
        ```shell
        sleep 5  0,00s user 0,00s system 0% cpu 5,006 total
        ```

    1. L'affichage loopcpu:
        ```shell
        ./loopcpu  8,97s user 0,00s system 99% cpu 8,977 total
        ```
        On constate que la plupart du temps est passé en mode user, et la somme du temps en mode user et kernel est inférieure au temps réel.

    1. L'affichage loopsys:
        ```shell
        ./loopsys  0,22s user 0,00s system 99% cpu 0,230 total
        ```
        De même, on constate que la plupart du temps est encore passé en mode user, et la somme du temps en mode user et kernel est aussi inférieure au temps réel.

1. Lancement commande shell (voir le code)

1. Calcul du temps (voir le code)

1. Calcul des statistiques
    1. voir le code pour
    1. les affichages:
        ```shell
        $ ./mytimes2 "sleep 5" ./loopsys ./loopcpu
        Commande : sleep 5
        Temps total: 5.002745
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 0.000000
        Temps système fils: 0.000000
        Commande : ./loopsys
        Temps total: 0.129191
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 0.120000
        Temps système fils: 0.000000
        Commande : ./loopcpu
        Temps total: 8.980207
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 8.970000
        Temps système fils: 0.000000
        ```

1. Changement de priorité

    1. priorité de ps : 80
        ```shell
        F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
        0 S  1000  4306  4204  0  80   0 -  7967 sigsus pts/1    00:00:00 zsh
        0 R  1000  6091  4306  0  80   0 -  9142 -      pts/1    00:00:00 ps
        ```

    1. priorité de la commande : 99
        ```shell
        F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
        0 S  1000  4306  4204  0  80   0 -  7967 sigsus pts/1    00:00:00 zsh
        0 R  1000  7244  4306  0  99  19 -  9142 -      pts/1    00:00:00 ps
        ```

    1. Si on baisse la priorité, alors le processus touché [6]23433 donne son résultat plus rapidement.
        ```shell
        # script tourné via zsh
        ➜  TME2 git:(master) ✗
        for i in $(seq 1 9)      
        do
                if [ $i = 4 ]
            then
                        nice -n -18 ./mytimes2 ./loopcpu &
                else
                        ./mytimes2 ./loopcpu &
                fi
        done
        ```
        ce qui donne l'affichage suivant :
        ```shell
        [3] 23428
        [4] 23429
        [5] 23431
        [6] 23433
        [7] 23435
        [8] 23436
        [9] 23440
        [10] 23445
        [11] 23447
        ➜  TME2 git:(master) ✗ Commande : ./loopcpu
        Temps total: 9.296894
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.260000
        Temps système fils: 0.010000

        [6]    23433 done       nice -n -18 ./mytimes2 ./loopcpu
        ➜  TME2 git:(master) ✗ Commande : ./loopcpu
        Temps total: 21.633890
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.290000
        Temps système fils: 0.020000

        [4]    23429 done       ./mytimes2 ./loopcpu
        ➜  TME2 git:(master) ✗ Commande : ./loopcpu
        Temps total: 22.100417
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.300000
        Temps système fils: 0.000000

        [7]    23435 done       ./mytimes2 ./loopcpu
        ➜  TME2 git:(master) ✗ Commande : ./loopcpu
        Temps total: 22.369032
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.300000
        Temps système fils: 0.010000

        [5]    23431 done       ./mytimes2 ./loopcpu
        ➜  TME2 git:(master) ✗ Commande : ./loopcpu
        Temps total: 22.888488
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.320000
        Temps système fils: 0.010000

        [9]    23440 done       ./mytimes2 ./loopcpu
        ➜  TME2 git:(master) ✗ Commande : ./loopcpu
        Temps total: 23.161449
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.290000
        Temps système fils: 0.010000

        [8]    23436 done       ./mytimes2 ./loopcpu
        Commande : ./loopcpu
        Temps total: 23.149493
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.300000
        Temps système fils: 0.010000
        [11]  + 23447 done       ./mytimes2 ./loopcpu
        ➜  TME2 git:(master) ✗ ➜  TME2 git:(master) ✗ Commande : ./loopcpu
        Temps total: 23.864221
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.310000
        Temps système fils: 0.020000

        [10]  + 23445 done       ./mytimes2 ./loopcpu
        Commande : ./loopcpu
        Temps total: 23.906371
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.300000
        Temps système fils: 0.010000
        [3]  + 23428 done       ./mytimes2 ./loopcpu
        ```