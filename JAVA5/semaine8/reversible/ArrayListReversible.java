import java.util.ArrayList;

class ArrayListReversible extends ArrayList<Object> implements Reversible{

    /**
     *
     */
    private static final long serialVersionUID = 6516963951434310223L;
    private boolean reversible;

    
    
    @Override
    public void reverse() {
        checkReversibility();
        if(!reversible){
            System.out.println("The structure is not reversible.");
            return;
        }
        for (Object rev : this) {
            if(rev instanceof Reversible){
                ((Reversible) rev).reverse();
            }
            
        }
        ArrayListReversible tmp = new ArrayListReversible();
        for (int i = this.size() - 1; i >= 0 ; i--) {
            tmp.add(this.get(i));
            this.remove(i);
        }
        for (int i = 0; i < this.size(); i++) {
            this.add(tmp.get(i));
        }
    }

    @Override
    public String toString() {
        String s = "ArrayListReversible [reversible=" + reversible + "]";
        for (Object object : this) {
            s += object.toString() + "\n";
        }
        return s;
    }

    public boolean checkReversibility() {
        reversible = true;
        for (Object object : this) {
            if(!(object instanceof Reversible)){
                reversible = false;
                return reversible;
            }
        }
        return reversible;
    }

    public boolean isReversible() {
        return reversible;
    }

    
}