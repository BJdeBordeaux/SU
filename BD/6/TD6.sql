--1.1

--IN
SELECT nomath, prenomath FROM athlete
WHERE aid IN (
    SELECT aid FROM rangindividuel
)
AND aid IN (
    SELECT aid FROM athletequipe ae, rangequipe re
    WHERE ae.eqid=re.eqid
);

--EXISTS
SELECT nomath, prenomath FROM athlete a
WHERE EXISTS (
    SELECT * FROM rangindividuel ri
    WHERE a.aid=ri.aid
)
AND EXISTS (
    SELECT * FROM athletequipe ae, rangequipe re
    WHERE ae.eqid=re.eqid AND ae.aid=a.aid
);

--ANY
SELECT nomath, prenomath FROM athlete a
WHERE = ANY (
    SELECT * FROM rangindividuel ri
    WHERE a.aid=ri.aid
)
AND = ANY (
    SELECT * FROM athletequipe ae, rangequipe re
    WHERE ae.eqid=re.eqid AND ae.aid=a.aid
);

--1.2.a
SELECT nomp FROM pays
WHERE codepays IN (
    SELECT codepays FROM athlete
);

--1.2.b
SELECT nomp FROM pays
WHERE codepays IN (
    SELECT codepays FROM athlete
    WHERE NOT EXISTS (
        SELECT * FROM athlete a2
        WHERE a2.codepays=p.codepays
        AND a2.aid<>a.aid
    )
);

--1.3.b
SELECT nomp FROM pays p 
WHERE NOT EXISTS (
    SELECT * FROM athlete a, rangindividuel ri
    WHERE a.codepays=p.codepays 
    AND a.aid=ri.aid
    AND ri.rang IS NULL
) AND EXISTS(
    SELECT * FROM athlete a2
    WHERE a2.codepays=p.codepays
);

-- 1.4.a 4. a) Les athlètes n'ayant pas gagné de médaille ni en individuel ni en équipe
Résultat : (1921 lignes)
SELECT nomath, prenomath FROM athlete a
WHERE NOT EXISTS (
    SELECT * FROM rangindividuel ri 
    WHERE ri.aid=a.aid AND ri.rang<=3
) AND NOT EXISTS (
    SELECT * FROM athletesequipe ae, rangequipe re
    WHERE ae.aid=a.aid AND ae.eqid=re.eqid AND re.rang<=3
);

-- b) Les pays ayant participé aux JO et n'ayant pas gagné de médaille ni en individuel ni en équipe.
Résultat : (63 lignes) ??
SELECT DISTINCT nomp FROM pays p WHERE NOT EXISTS (
    SELECT * FROM rangindividuel ri, athlete a
    WHERE ri.aid=a.aid AND a.codepays=p.codepays AND ri.rang<=3
) AND NOT EXISTS (
    SELECT * FROM rangequipe re, equipe e
    WHERE re.eqid=e.eqid AND e.codepays=p.codepays AND re.rang<=3
) AND ( EXISTS (
    SELECT * FROM rangindividuel ri, athlete a,
    WHERE ri.aid=a.aid AND a.codepays=p.codepays
) OR EXISTS (
    SELECT * FROM rangequipe re, equipe e
    WHERE re.eqid=e.eqid AND e.codepays=p.codepays
));

-- 5. L'(es) épreuve(s) avec la plus grande durée.
Résultat : Hockey sur glace, Hockey sur glace, Hommes, 15 jours


-- 6. Les athlètes ayant gagné une médaille à toutes les épreuve individuelles auxquelles ils ont participé.
Résultat : (109 lignes) ??
SELECT nomath, prenomath FROM athlete a WHERE NOT EXISTS (
    SELECT * FROM rangindividuel ri 
    WHERE ri.aid=a.aid AND ri.rang>3
) AND EXISTS (
    SELECT * FROM rangindividuel ri 
    WHERE ri.aid=a.aid
);


-- On reprend le schéma « Foofle ». Exprimez les requêtes suivantes de plusieurs manières, en utilisant des jointures, ainsi que les opérateurs EXISTS, ANY, ALL:
Sponsorise(NSp, NJo, Somme), 
Joueur(NJo, Eq, Taille, Age), 
Equipe(NEq, Ville, Couleur, StP) 
Match(Eq1, Eq2, DateM, St), 
Distance(St1, St2, NbKm)

--7. Quelles équipes ont déjà joué au stade préféré de l'équipe des Piepla ?

8. Quels sont les stades où a déjà joué Manon Messi ?

9. A quelle date a eu lieu un match entre deux équipes sponsorisées par le même sponsor ?

10. Quel sponsor a financé deux joueurs différents ayant eu un match le même jour et dans des stades différents mais proches (moins de 50 km) ?

--EX2

Exprimez les requêtes suivantes en SQL sur la base de données Jeux Olympiques 2014:

--1. Les sports dont toutes les épreuves ont duré un seul jour.
Résultat attendu: Ski de fond, Ski alpin, Biathlon
SELECT nomsp FROM sport s WHERE NOT EXISTS (
    SELECT * FROM epreuve e 
    WHERE e.datefin-e.datedebut<>0 AND e.sid=s.sid
);


--2. Les sports qui n'ont pas d'épreuves de categorie Mixte.
Résultat attendu: (12 lignes)
SELECT nomsp FROM sport s WHERE NOT EXISTS (
    SELECT * FROM epreuve e
    WHERE e.categorie='Mixte' AND e.sid=s.sid
);

--3. Les équipes dont aucun athlète n'a gagné de médaille aux épreuves individuelles. Attention : il y a des équipes sans athlètes.
Résultat attendu: (265 lignes avec les équipes sans athlètes - 252 lignes sans les équipes sans athlètes)
SELECT eqid FROM equipe eq WHERE NOT EXISTS (
    SELECT * FROM athletesequipe ae, rangindividuel ri
    WHERE ae.aid=ri.aid AND ae.eqid=eq.eqid AND ri.rang<=3
);

--4. La nationalité de l'athlète le/la plus jeune. Attention : il y a des athlètes dont on ne connaît pas la date de naissance.
Résultat attendu: ('29/11/1998','JPN')
SELECT a.datenaissance, p.nomp FROM pays p, athlete a WHERE NOT EXISTS (
    SELECT * FROM athlete a2 WHERE a2.datenaissance IS NOT NULL AND a2.datenaissance>a.datenaissance
) AND a.datenaissance IS NOT NULL;

--5. Le plus jeune athlète de chaque pays.
Résultat attendu: (26 lignes)
SELECT a.datenaissance, a.nomath, prenomath FROM athlete a WHERE NOT EXISTS (
    SELECT * FROM athlete a2 WHERE a2.datenaissance IS NOT NULL 
    AND a2.datenaissance>a.datenaissance
    AND a2.codepays=a.codepays
) AND a.datenaissance IS NOT NULL;

--
SELECT TO_CHAR(datefin, 'YYYY-MM-DD') FROM epreuve;
SELECT datefin-datedebut FROM epreuve;