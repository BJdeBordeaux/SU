# TME2
### PAR Junji LI && Diego Arbulu
<hr>

1. Commandes Shell
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
        # pour sleep 5
        Temps total: 5.001772
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 0.000000
        Temps système fils: 0.000000
        # pour ./loopsys
        Temps total: 0.093892
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 0.090000
        Temps système fils: 0.000000
        # pour ./loopcpu
        Temps total: 9.551745
        Temps utilisateur: 0.000000
        Temps système: 0.000000
        Temps utilisateur fils: 9.340000
        Temps système fils: 0.020000
        ```

1. Changement de priorité

    1. priorité de ps : 80
        ```shell
        F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
        0 S  1000  4306  4204  0  80   0 -  7967 sigsus pts/1    00:00:00 zsh
        0 R  1000  6091  4306  0  80   0 -  9142 -      pts/1    00:00:00 ps
        ```

    1. priorité de la commande : 19
        ```shell
        F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
        0 S  1000  4306  4204  0  80   0 -  7967 sigsus pts/1    00:00:00 zsh
        0 R  1000  7244  4306  0  99  19 -  9142 -      pts/1    00:00:00 ps
        ```