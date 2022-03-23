# http : protocol de communication entre client/server
1. REST: spécification qui répond sur HTTP s'appui sur service
    1. Utilisateur (api/user)
        * get : select dans la database : récupérer des info sur l'user
        * put : insert : ajouter utilisateur
        * post : update : ajouter d'information sur user
        * delete : supprimer un user
    1. Message (api/message)
        * get : récupérer un msg
        * put : publier(créer)
        * post : modifier // (récupérer un msg spécifique)
        * delete : supprimer
    1. Authentification/Connexion
        * put : créer une connexion
        * delete : supprimer
    1. Friend
        * get : afficher les amis
        * post : afficer un ami spécifique
        * put : ajouter (abonner) un ami
        * delete : supprimer (desabonner) un ami

1. Tester : avec `postman`

1. table d'exemple

    |  Nom du service   | Create User  |
    |  ----  | ----  |
    | URL  | user/put |
    | Desc  | ajouter un user dans database |
    | param  | username, nom, prénom, password, adresse... |
    | format de sortie  | OK/Err |
    | exemple de sortie  | `{status: 201, message: "created", detail: "..."}` |
    | err possibles  | params manquant/invalide (400)<br/>user exists(409)<br/>problème de DB (500) |
    | avancement  | ... |
    | fichiers/classes Javascript  | ... |
    | Info additionnelle  | ... |

## Create User
<hr/>

```python
    if(!validated(params)):
        return {status: 400, msg: "missing params"}
    if(exist(username)):
        return {status: 409, msg: "user exists"}
    try:
        BD.add(user)
    except BD_problem:
        return {status: 500, msg: "BD problem"}
    return {status: 201, msg: "created"}
```

## Log In
<hr/>

|  Nom du service   | Log In |
|  ----  | ----  |
| URL  | `authentification/` (put) |
| Desc  | permet de récupérer une clé de connexion valide |
| param  | username, password |
| format de sortie  | OK/Err |
| exemple de sortie  | `{status: 401, message: "created", detail: "..."}` |
| err possibles  | password incorrect (401)<br/>user inconnu (401)<br/>problème de DB (500) |
| avancement  | ... |
| fichiers/classes Javascript  | ... |
| Info additionnelle  | ... |

```python
    if(!validated(params)):
        return {status: 400, msg: "missing params"}
    if(!exist(username)):
        return {status: 401, msg: "user exists"}
    if(!validated(password)):
        return {status: 401, msg: "wrong password"}
    try:
        create(clef_connexion) # par express_session
    except BD_problem:
        return {status: 500, msg: "BD problem"}
    return {status: 201, msg: "login success", ConnectionKey: clef_connexion}
```