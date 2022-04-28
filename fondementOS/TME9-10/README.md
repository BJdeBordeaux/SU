# Rapport de TME9-10
### par LI Junji 28610187 && Mohamed BABAALI 28601465

1. Taille maximale d'un fichier
    1. Un fichier de taille maximale prend toutes les entrées de la table FAT  sauf la dernière qui est -1 : `NB_ENT_FAT` - 1 =  127 entrée au total. Chaque entrée représente `SIZE_SECTOR` = 128 octets, donc 127*128 = 16 256 octets = 15.88 Ko.
1. voir le code