# implémentation des Web Service MongoDB
1. Rappel de cours
    1. simplicité
        1. performance
        1. traitement par batch
    1. Documents (json, xml, yaml, pdf)
    1. réaliser une connexion/déconnexion
        ```js
            var datastore = require('nedb');
            db = new DataStore();
            db.users = new DataStore();
            db.messages = new DataStore();
            // charger collections
            db.users.loadDatabase(path)
        ```

1. mongoDB
    1. exemple de message
        ```json
            _id: "e34grzgd344646543"
            author_id: 1,
            author_name: user,
            date: date,
            text: "mon message",
            like: [author_id: 2 ...],
            comment: [comment_id: 1, ...]
        ```
        `db.messages.insert({author_id: 3, name: Junji, date: X, text: "text"})`
    1. afficher un message
        ```js
            // {}: no filter, {text: 1, _id: 1}: get text and id, callback function
            db.messages.find({}, {text: 1, _id: 1}, (err,docs)=>{
                console.log(docs);
            })
        ```
    1. message from a certain user
        ```js
            // mask
            const masque = {author_id: 158};
            const toFind = {text: 1, _id: 1};
            const cb_fun = (err, docs)=>{
                console.log(docs);
            }
            // find
            db.message.find(mask, toFind, cb_fun);
        ```
    1. get messages from another user
        ```js
            const getMessageId = function(idA, text){
                return new Promise((resolve, reject)=>{
                    const masque = {author_id: idA, text: text};
                    const toFind = {author_id: 1, _id: 1};
                    const cb_fun = (err, docs)=>{
                        if(err){
                            reject(err);
                        }else{
                            resolve(docs[0].id);
                        }
                    }
                    db.messages.find(masque, toFind, cb_fun);
                })
            }
            getMessageID("158", "mon message")
            .then((id)=>{
                console.log(id);
                db.messages.find({_id: id}, {}, (err, doc)=>{
                    console.log(doc);
                })
            })
        ```
1. mongoDB et les dates
    1. message moins d'une heure
        ```js
            db.messages.find({date: {new Date(Date().now()-60*60*1000)}}, (err, docs)=>{
                console.log(docs);
            })
        ```

1. mongoDB et les opérateurs conditionnelles
    1. messages par author 155, 198
        ```js
            db.messages.find({"author_id": {$in: [155, 198]}})
        ```

