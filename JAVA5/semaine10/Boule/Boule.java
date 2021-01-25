public class Boule {
    private String couleur;

    public Boule (String couleur) {
        this.couleur = couleur;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((couleur == null) ? 0 : couleur.hashCode());
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj){return true;}
        if(obj == null){return false;}
        if(obj.getClass() != this.getClass()){return false;}
        Boule other = (Boule) obj;
        if(!other.couleur.equals(this.couleur)){return false;}
        return true;
    }
}



/*        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Boule other = (Boule) obj;
        if (couleur == null) {
            if (other.couleur != null)
                return false;
        } else if (!couleur.equals(other.couleur))
            return false;
        return true;*/