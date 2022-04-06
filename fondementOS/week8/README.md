# Rapport de TME8
### par LI Junji 28610187 && Mohamed BABAALI 28601465
<hr>

1. FIFO
    affichage:
        ```
            Page 1 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 0 has been choosen
            (frame 0: 1) (frame 1: _) (frame 2: _) 

            Page 2 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 1 has been choosen
            (frame 0: 1) (frame 1: 2) (frame 2: _) 

            Page 3 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 2 has been choosen
            (frame 0: 1) (frame 1: 2) (frame 2: 3) 

            Page 1 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 3) 

            Page 2 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 3) 

            Page 4 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 0 has been choosen
            (frame 0: 4) (frame 1: 2) (frame 2: 3) 

            Page 1 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 0 has been choosen
            (frame 0: 1) (frame 1: 2) (frame 2: 3) 

            Page 2 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 3) 

            Page 4 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 0 has been choosen
            (frame 0: 4) (frame 1: 2) (frame 2: 3) 

            Page 4 referenced
            (frame 0: 4) (frame 1: 2) (frame 2: 3) 

            6/10 ~ 60.000000%

2. LRU
    affichage
        ```shell
            Page 1 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 0 has been choosen
            (frame 0: 1) (frame 1: _) (frame 2: _) 

            Page 2 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 1 has been choosen
            (frame 0: 1) (frame 1: 2) (frame 2: _) 

            Page 3 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 2 has been choosen
            (frame 0: 1) (frame 1: 2) (frame 2: 3) 

            Page 1 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 3) 

            Page 2 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 3) 

            Page 4 referenced
            /!\ PAGE FAULT !!! /!\
            Frame 2 has been choosen
            (frame 0: 1) (frame 1: 2) (frame 2: 4) 

            Page 1 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 4) 

            Page 2 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 4) 

            Page 4 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 4) 

            Page 4 referenced
            (frame 0: 1) (frame 1: 2) (frame 2: 4) 

            4/10 ~ 40.000000%
        
3. Comparaison
    Au niveau du taux de défaut de page, on constate que l'algorithme `LRU` a la meuilleure performance comparé à `FIFO` et `random`. En changeant les entrés, on a le même constat, avec `LRU` 47.37% et `FIFO` 57.89%.