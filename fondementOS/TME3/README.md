# Rapport de TME1
### par LI Junji 28610187 && Mohamed BABAALI 28601465

1. Tester la bibliothèque
    1. copie-collé : fait
    1. test : fait
        avec `SchedParam(NEW, 0.3, RandomElect);`, on a affichage:
            ```shell
            ...
            PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
            --------------------------------------------------------------------
            0       Function0       2.935s          1.090s          1.845s
            1       Function1       2.445s          1.082s          1.363s
            2       Function2       0.983s          0.383s          0.600s
            3       Function3       1.063s          0.380s          0.683s
            --------------------------------------------------------------------
            Average:                1.856s          0.734s          1.123s
            --------------------------------------------------------------------
            ```
    
    1. On a remarqué que avec la différence entre les valeurs du quantum,  REAL-TIME, CPU-TIME, WAITING-TIME des fonctions se varient
        1. avec `SchedParam(NEW, 0.0, RandomElect);`, on a affichage:
            ```shell
            ...
            PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
            --------------------------------------------------------------------
            0       Function0       1.764s          1.038s          0.726s
            1       Function1       2.835s          1.071s          1.764s
            2       Function2       0.726s          0.356s          0.370s
            3       Function3       0.370s          0.370s          0.000s
            --------------------------------------------------------------------
            Average:                1.424s          0.709s          0.715s
            --------------------------------------------------------------------
            ```

        1. avec `SchedParam(NEW, 0.6, RandomElect);`, qui resemble à l'exemple précédent, on a affichage :
            ```shell
            ...
            PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
            --------------------------------------------------------------------
            0       Function0       3.100s          1.171s          1.930s
            1       Function1       2.530s          1.192s          1.338s
            2       Function2       0.738s          0.377s          0.361s
            3       Function3       0.361s          0.361s          0.000s
            --------------------------------------------------------------------
            Average:                1.682s          0.775s          0.907s
            --------------------------------------------------------------------
            ```
        
        1. avec `SchedParam(NEW, 0.15, RandomElect);`, on a affichage :
            ```shell
            ...
            PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
            --------------------------------------------------------------------
            0       Function0       2.929s          1.104s          1.825s
            1       Function1       2.275s          1.107s          1.168s
            2       Function2       0.799s          0.349s          0.450s
            3       Function3       1.167s          0.368s          0.799s
            --------------------------------------------------------------------
            Average:                1.793s          0.732s          1.061s
            --------------------------------------------------------------------
            ```

        1. avec `SchedParam(NEW, 0.05, RandomElect);`, on a affichage :
            ```shell
            ...
            PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
            --------------------------------------------------------------------
            0       Function0       3.061s          1.204s          1.857s
            1       Function1       2.356s          1.152s          1.204s
            2       Function2       1.053s          0.354s          0.699s
            3       Function3       1.049s          0.348s          0.701s
            --------------------------------------------------------------------
            Average:                1.880s          0.764s          1.115s
            --------------------------------------------------------------------
            ```
1. SJF
    1. fait
    1. Le programme génère 2 processus longs au départ avec `l0`, `l1`
        1. `SchedParam(NEW, 0, SJFElect);`
            1. L'affichage suivant nous indique que on exécute d'abord le processus `l0`
            1. puis les processus courts que celui de long génère: `c2`, `c3`, `c4`, `c5`, qui sont les plus courts (on a `l1` qui est aussi prêt)
            1. `l0` et `c2`, `c3`, `c4`, `c5`,  se termine, `l1` et `c6`, `c7`, `c8`, `c9` sont exécutés de la même manière 
        1. `SchedParam(NEW, 0.3, SJFElect);`
            1. L'affichage suivant nous indique que on exécute d'abord le processus `l0`
            1. Une fois un processus court crée, il sera exécuté, et puis, on bascule sur le processus long
            1. Le temps d'attente moyen est donc diminué.
        ```shell
        `SchedParam(NEW, 0, SJFElect);`
        PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
        --------------------------------------------------------------------
        0       Function0       3.264s          3.264s          0.000s
        1       Function1       7.445s          3.262s          4.183s
        2       Function2       3.516s          0.253s          3.264s
        3       Function3       2.939s          0.226s          2.713s
        4       Function4       2.336s          0.223s          2.113s
        5       Function5       1.731s          0.218s          1.513s
        6       Function6       3.480s          0.219s          3.262s
        7       Function7       2.868s          0.218s          2.650s
        8       Function8       2.278s          0.216s          2.062s
        9       Function9       1.670s          0.215s          1.455s
        --------------------------------------------------------------------
        Average:                3.153s          0.831s          2.322s
        --------------------------------------------------------------------
        ```

        ```shell
        `SchedParam(NEW, 0.3, SJFElect);`
        PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
        --------------------------------------------------------------------
        0       Function0       4.255s          3.376s          0.879s
        1       Function1       8.353s          3.243s          5.110s
        2       Function2       0.527s          0.227s          0.300s
        3       Function3       0.274s          0.223s          0.052s
        4       Function4       0.312s          0.218s          0.095s
        5       Function5       0.370s          0.211s          0.159s
        6       Function6       0.513s          0.213s          0.300s
        7       Function7       0.299s          0.214s          0.085s
        8       Function8       0.375s          0.215s          0.160s
        9       Function9       0.462s          0.213s          0.249s
        --------------------------------------------------------------------
        Average:                1.574s          0.835s          0.739s
        --------------------------------------------------------------------
        ```
1. ASJF
    1. on a obtenu l'affichage suivant:
        ```shell
        SchedParam(NEW, 0., ApproxSJF);
        PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
        --------------------------------------------------------------------
        0       Function0       3.202s          3.202s          0.000s
        1       Function1       7.615s          3.562s          4.053s
        2       Function2       4.053s          0.214s          3.840s
        3       Function3       3.044s          0.211s          2.833s
        4       Function4       2.050s          0.218s          1.832s
        5       Function5       1.021s          0.209s          0.812s
        6       Function6       4.489s          0.231s          4.258s
        7       Function7       3.450s          0.234s          3.216s
        8       Function8       2.321s          0.242s          2.079s
        9       Function9       1.175s          0.220s          0.955s
        --------------------------------------------------------------------
        Average:                3.242s          0.854s          2.388s
        --------------------------------------------------------------------
        ```
    1. on a obtenu l'affichage suivant. Le temps d'attente moyen est diminué par rapport au `SchedParam(NEW, 1., RandomElect);`
        ```shell
        SchedParam(NEW, 1., SJF);
        PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
        --------------------------------------------------------------------
        0       Function0       7.973s          3.233s          4.740s
        1       Function1       8.239s          3.266s          4.973s
        2       Function2       1.429s          0.219s          1.210s
        3       Function3       0.410s          0.210s          0.199s
        4       Function4       1.434s          0.216s          1.218s
        5       Function5       0.413s          0.218s          0.194s
        6       Function6       0.593s          0.215s          0.378s
        7       Function7       0.568s          0.222s          0.347s
        8       Function8       0.805s          0.226s          0.579s
        9       Function9       0.747s          0.213s          0.534s
        --------------------------------------------------------------------
        Average:                2.261s          0.824s          1.437s
        --------------------------------------------------------------------
        ```

        ```shell
        SchedParam(NEW, 1., RandomElect);
        PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
        --------------------------------------------------------------------
        0       Function0       8.499s          3.341s          5.158s
        1       Function1       5.968s          3.304s          2.664s
        2       Function2       1.223s          0.223s          1.000s
        3       Function3       0.651s          0.219s          0.432s
        4       Function4       4.756s          0.231s          4.525s
        5       Function5       4.151s          0.255s          3.896s
        6       Function6       0.553s          0.221s          0.333s
        7       Function7       2.553s          0.244s          2.309s
        8       Function8       2.651s          0.227s          2.424s
        9       Function9       1.004s          0.234s          0.770s
        --------------------------------------------------------------------
        Average:                3.201s          0.850s          2.351s
        --------------------------------------------------------------------
        ```
    1. À priori, Non. On peut voir depuis le début, peu import la duration du processus, ils sont exécutés.
        Or, si on ajoute des tâches de petit ncpu au fur et à mesure, ils ont une priorité plus élevée grâce à leur ncpu qui est nul. Donc les processus longs qui ont consommé des ncpu auront un risque de famine.
        ```shell
        ASJF Election !
        Proc. Long 0 - 0
        Proc. Long 0 - 8000000
        Proc. Long 0 - 16000000
        Proc. Long 0 - 24000000
        Proc. Long 0 - 32000000
        Proc. Long 0 - 40000000
        Proc. Long 0 - 48000000
        Proc. Long 0 - 56000000
        Proc. Long 0 - 64000000
        Proc. Long 0 - 72000000
        Proc. Long 0 - 80000000
        Proc. Long 0 - 88000000
        Proc. Long 0 - 96000000
        Proc. Long 0 - 104000000
        Proc. Long 0 - 112000000
        Proc. Long 0 - 120000000
        Proc. Long 0 - 128000000
        Proc. Long 0 - 136000000
        Proc. Long 0 - 144000000
        Proc. Long 0 - 152000000
        Proc. Long 0 - 160000000
        Proc. Long 0 - 168000000
        Proc. Long 0 - 176000000
        Proc. Long 0 - 184000000
        Proc. Long 0 - 192000000
        Proc. Long 0 - 200000000
        Proc. Long 0 - 208000000
        Proc. Long 0 - 216000000
        Proc. Long 0 - 224000000
        Proc. Long 0 - 232000000
        Proc. Long 0 - 240000000
        Proc. Long 0 - 248000000
        ASJF Election !
        Proc. Court 1 - 0
        Proc. Court 1 - 8000000
        Proc. Court 1 - 16000000
        Proc. Court 1 - 24000000
        Proc. Court 1 - 32000000
        Proc. Court 1 - 40000000
        Proc. Court 1 - 48000000
        Proc. Court 1 - 56000000
        Proc. Court 1 - 64000000
        Proc. Court 1 - 72000000
        ############ FIN COURT 1

        ASJF Election !
        Proc. Court 0 - 0
        Proc. Court 0 - 8000000
        Proc. Court 0 - 16000000
        Proc. Court 0 - 24000000
        Proc. Court 0 - 32000000
        Proc. Court 0 - 40000000
        Proc. Court 0 - 48000000
        Proc. Court 0 - 56000000
        Proc. Court 0 - 64000000
        Proc. Court 0 - 72000000
        ############ FIN COURT 0

        ASJF Election !
        Proc. Long 1 - 0
        Proc. Long 1 - 8000000
        Proc. Long 1 - 16000000
        Proc. Long 1 - 24000000
        Proc. Long 1 - 32000000
        Proc. Long 1 - 40000000
        Proc. Long 1 - 48000000
        Proc. Long 1 - 56000000
        Proc. Long 1 - 64000000
        Proc. Long 1 - 72000000
        Proc. Long 1 - 80000000
        Proc. Long 1 - 88000000
        Proc. Long 1 - 96000000
        Proc. Long 1 - 104000000
        Proc. Long 1 - 112000000
        Proc. Long 1 - 120000000
        Proc. Long 1 - 128000000
        Proc. Long 1 - 136000000
        Proc. Long 1 - 144000000
        Proc. Long 1 - 152000000
        Proc. Long 1 - 160000000
        Proc. Long 1 - 168000000
        Proc. Long 1 - 176000000
        Proc. Long 1 - 184000000
        Proc. Long 1 - 192000000
        Proc. Long 1 - 200000000
        Proc. Long 1 - 208000000
        Proc. Long 1 - 216000000
        Proc. Long 1 - 224000000
        Proc. Long 1 - 232000000
        Proc. Long 1 - 240000000
        Proc. Long 1 - 248000000
        ASJF Election !
        Proc. Court 3 - 0
        Proc. Court 3 - 8000000
        Proc. Court 3 - 16000000
        Proc. Court 3 - 24000000
        Proc. Court 3 - 32000000
        Proc. Court 3 - 40000000
        Proc. Court 3 - 48000000
        Proc. Court 3 - 56000000
        Proc. Court 3 - 64000000
        Proc. Court 3 - 72000000
        ############ FIN COURT 3

        ASJF Election !
        Proc. Court 2 - 0
        Proc. Court 2 - 8000000
        Proc. Court 2 - 16000000
        Proc. Court 2 - 24000000
        Proc. Court 2 - 32000000
        Proc. Court 2 - 40000000
        Proc. Court 2 - 48000000
        Proc. Court 2 - 56000000
        Proc. Court 2 - 64000000
        Proc. Court 2 - 72000000
        ############ FIN COURT 2

        ASJF Election !
        Proc. Long 0 - 256000000
        Proc. Long 0 - 264000000
        Proc. Long 0 - 272000000
        Proc. Long 0 - 280000000
        Proc. Long 0 - 288000000
        Proc. Long 0 - 296000000
        Proc. Long 0 - 304000000
        Proc. Long 0 - 312000000
        Proc. Long 0 - 320000000
        Proc. Long 0 - 328000000
        Proc. Long 0 - 336000000
        Proc. Long 0 - 344000000
        Proc. Long 0 - 352000000
        Proc. Long 0 - 360000000
        Proc. Long 0 - 368000000
        Proc. Long 0 - 376000000
        Proc. Long 0 - 384000000
        Proc. Long 0 - 392000000
        Proc. Long 0 - 400000000
        Proc. Long 0 - 408000000
        Proc. Long 0 - 416000000
        Proc. Long 0 - 424000000
        Proc. Long 0 - 432000000
        Proc. Long 0 - 440000000
        Proc. Long 0 - 448000000
        Proc. Long 0 - 456000000
        Proc. Long 0 - 464000000
        Proc. Long 0 - 472000000
        Proc. Long 0 - 480000000
        Proc. Long 0 - 488000000
        ASJF Election !
        Proc. Court 4 - 0
        Proc. Court 4 - 8000000
        Proc. Court 4 - 16000000
        Proc. Court 4 - 24000000
        Proc. Court 4 - 32000000
        Proc. Court 4 - 40000000
        Proc. Court 4 - 48000000
        Proc. Court 4 - 56000000
        Proc. Court 4 - 64000000
        Proc. Court 4 - 72000000
        ############ FIN COURT 4

        ASJF Election !
        Proc. Long 1 - 256000000
        Proc. Long 1 - 264000000
        Proc. Long 1 - 272000000
        Proc. Long 1 - 280000000
        Proc. Long 1 - 288000000
        Proc. Long 1 - 296000000
        Proc. Long 1 - 304000000
        Proc. Long 1 - 312000000
        Proc. Long 1 - 320000000
        Proc. Long 1 - 328000000
        Proc. Long 1 - 336000000
        Proc. Long 1 - 344000000
        Proc. Long 1 - 352000000
        Proc. Long 1 - 360000000
        Proc. Long 1 - 368000000
        Proc. Long 1 - 376000000
        Proc. Long 1 - 384000000
        Proc. Long 1 - 392000000
        Proc. Long 1 - 400000000
        Proc. Long 1 - 408000000
        Proc. Long 1 - 416000000
        Proc. Long 1 - 424000000
        Proc. Long 1 - 432000000
        Proc. Long 1 - 440000000
        Proc. Long 1 - 448000000
        Proc. Long 1 - 456000000
        Proc. Long 1 - 464000000
        Proc. Long 1 - 472000000
        Proc. Long 1 - 480000000
        Proc. Long 1 - 488000000
        Proc. Long 1 - 496000000
        ASJF Election !
        Proc. Court 5 - 0
        Proc. Court 5 - 8000000
        Proc. Court 5 - 16000000
        Proc. Court 5 - 24000000
        Proc. Court 5 - 32000000
        Proc. Court 5 - 40000000
        Proc. Court 5 - 48000000
        Proc. Court 5 - 56000000
        Proc. Court 5 - 64000000
        Proc. Court 5 - 72000000
        ############ FIN COURT 5

        ASJF Election !
        Proc. Long 0 - 496000000
        Proc. Long 0 - 504000000
        Proc. Long 0 - 512000000
        Proc. Long 0 - 520000000
        Proc. Long 0 - 528000000
        Proc. Long 0 - 536000000
        Proc. Long 0 - 544000000
        Proc. Long 0 - 552000000
        Proc. Long 0 - 560000000
        Proc. Long 0 - 568000000
        Proc. Long 0 - 576000000
        Proc. Long 0 - 584000000
        Proc. Long 0 - 592000000
        Proc. Long 0 - 600000000
        Proc. Long 0 - 608000000
        Proc. Long 0 - 616000000
        Proc. Long 0 - 624000000
        Proc. Long 0 - 632000000
        Proc. Long 0 - 640000000
        Proc. Long 0 - 648000000
        Proc. Long 0 - 656000000
        Proc. Long 0 - 664000000
        Proc. Long 0 - 672000000
        Proc. Long 0 - 680000000
        Proc. Long 0 - 688000000
        Proc. Long 0 - 696000000
        Proc. Long 0 - 704000000
        Proc. Long 0 - 712000000
        Proc. Long 0 - 720000000
        Proc. Long 0 - 728000000
        Proc. Long 0 - 736000000
        ASJF Election !
        Proc. Court 6 - 0
        Proc. Court 6 - 8000000
        Proc. Court 6 - 16000000
        Proc. Court 6 - 24000000
        Proc. Court 6 - 32000000
        Proc. Court 6 - 40000000
        Proc. Court 6 - 48000000
        Proc. Court 6 - 56000000
        Proc. Court 6 - 64000000
        Proc. Court 6 - 72000000
        ############ FIN COURT 6

        ASJF Election !
        Proc. Long 1 - 504000000
        Proc. Long 1 - 512000000
        Proc. Long 1 - 520000000
        Proc. Long 1 - 528000000
        Proc. Long 1 - 536000000
        Proc. Long 1 - 544000000
        Proc. Long 1 - 552000000
        Proc. Long 1 - 560000000
        Proc. Long 1 - 568000000
        Proc. Long 1 - 576000000
        Proc. Long 1 - 584000000
        Proc. Long 1 - 592000000
        Proc. Long 1 - 600000000
        Proc. Long 1 - 608000000
        Proc. Long 1 - 616000000
        Proc. Long 1 - 624000000
        Proc. Long 1 - 632000000
        Proc. Long 1 - 640000000
        Proc. Long 1 - 648000000
        Proc. Long 1 - 656000000
        Proc. Long 1 - 664000000
        Proc. Long 1 - 672000000
        Proc. Long 1 - 680000000
        Proc. Long 1 - 688000000
        Proc. Long 1 - 696000000
        Proc. Long 1 - 704000000
        Proc. Long 1 - 712000000
        Proc. Long 1 - 720000000
        Proc. Long 1 - 728000000
        Proc. Long 1 - 736000000
        ASJF Election !
        Proc. Court 7 - 0
        Proc. Court 7 - 8000000
        Proc. Court 7 - 16000000
        Proc. Court 7 - 24000000
        Proc. Court 7 - 32000000
        Proc. Court 7 - 40000000
        Proc. Court 7 - 48000000
        Proc. Court 7 - 56000000
        Proc. Court 7 - 64000000
        Proc. Court 7 - 72000000
        ############ FIN COURT 7

        ASJF Election !
        Proc. Long 0 - 744000000
        Proc. Long 0 - 752000000
        Proc. Long 0 - 760000000
        Proc. Long 0 - 768000000
        Proc. Long 0 - 776000000
        Proc. Long 0 - 784000000
        Proc. Long 0 - 792000000
        ############ FIN LONG 0

        ASJF Election !
        Proc. Long 1 - 744000000
        Proc. Long 1 - 752000000
        Proc. Long 1 - 760000000
        Proc. Long 1 - 768000000
        Proc. Long 1 - 776000000
        Proc. Long 1 - 784000000
        Proc. Long 1 - 792000000
        ############ FIN LONG 1

        PID     FUNCTION        REAL-TIME       CPU-TIME        WAITING-TIME
        --------------------------------------------------------------------
        0       Function0       8.025s          3.237s          4.787s
        1       Function1       8.261s          3.236s          5.025s
        2       Function2       1.451s          0.225s          1.227s
        3       Function3       0.439s          0.227s          0.213s
        4       Function4       1.443s          0.223s          1.220s
        5       Function5       0.417s          0.220s          0.197s
        6       Function6       0.624s          0.232s          0.392s
        7       Function7       0.605s          0.214s          0.391s
        8       Function8       0.821s          0.240s          0.581s
        9       Function9       0.786s          0.207s          0.579s
        --------------------------------------------------------------------
        Average:                2.287s          0.826s          1.461s
        --------------------------------------------------------------------
        ```