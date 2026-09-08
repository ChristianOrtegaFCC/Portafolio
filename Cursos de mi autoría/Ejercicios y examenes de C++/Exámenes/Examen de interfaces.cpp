 //Tomando en consideración la interfaz:

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <memory>

enum class TTipoMaterial {
	gaseoso,
	liquido,
	contable
};

class CMaterial{
    private:
        std::string nombre;
    protected:
        float volumen;
    public:
        CMaterial(std::string _n): nombre(_n){}
        CMaterial(const CMaterial& m){ nombre = m.nombre;}
        std::string get_nombre() {return nombre;}
        void set_nombre(std::string n)  {nombre = n;}
        virtual std::string get_unidad_de_medida() = 0;
        virtual float get_cantidad() = 0;
        virtual void IncrementarInventario (float f) = 0;
        virtual TTipoMaterial get_tipo_material() = 0;
};

class Material_Gaseoso:public CMaterial{
protected:
    std::string unidad_de_volumen = "m3";
    float ctd;
public:

    // completar
    Material_Gaseoso(std::string n, float c): CMaterial(n), ctd(c){};
    Material_Gaseoso(const Material_Gaseoso& m): CMaterial(m), ctd(m.ctd){};
    virtual std::string get_unidad_de_medida() { return "m3"; };
    virtual TTipoMaterial get_tipo_material() { return TTipoMaterial::gaseoso; };
    virtual void IncrementarInventario (float f){ ctd += f; }
};

class Material_Contable{
private:
    float largo, alto, ancho; // Expresado en metros

    float get_volumen(){return largo * ancho * alto;}

protected:
    std::string unidad_de_volumen = "unidad";
    float ctd;
public:

    // completar
};

class Material_Liquido{
protected:
    std::string unidad_de_volumen = "m3";
    float ctd;
public:

    // completar
};

class CAlmacen{
private:
    std::unordered_map<std::string, std::shared_ptr<CMaterial>> productos;
public:
    CAlmacen& operator+= (CMaterial& m){
        std::string nombre{m.get_nombre()};
        if (productos.contains(nombre)){
            productos[nombre]->IncrementarInventario(m.get_cantidad());
        }else{
            switch (m.get_tipo_material()){
                case TTipoMaterial::gaseoso:{
                        productos[nombre] = std::make_shared<Material_Gaseoso>((const Material_Gaseoso&)m);
                    }
                    break;
//                case TTipoMaterial::liquido:
//                {
//                    productos[nombre] = std::make_shared<Material_Gaseoso>((const Material_Liquido&)m);
//                }
//                    break;
//                case TTipoMaterial::contable:
//                {
//                    productos[nombre] = std::make_shared<Material_Gaseoso>((const Material_Contable&)m);
//                }
//                    break;
            }
        }
        return *this;
    }

    void MostrarInventario(std::function<void (CMaterial&)> fcn){
        for(auto pair : productos){
            auto material = pair.second;
            fcn(*material);
        }
    }

    void MostrarInventario(std::function<void (CMaterial&)> fcn, TTipoMaterial p){
        for(auto pair : productos){
            auto material = pair.second;
            if ( /* Completar */ )
                fcn(*material);
        }
    }
};

int main() {
    std::cout << "Manejo de Inventarios" << std::endl;
    CAlmacen almacen;
    do{
        std::cout << "Nombre del Producto:";
        std::string nombre_producto;
        do{
            std::getline(std::cin, nombre_producto);
        }while(nombre_producto.empty());


        int tp;
        std::cout << "Tipo de Producto (1 - Gaseoso, 2 - Contable, 3 - Líquido): ";
        std::cin>>tp;

        float ctd;
        std::cout << "Cantidad a almacenar: ";
        std::cin>>ctd;

        switch (tp) {
            case 1: {
                auto gaseoso = Material_Gaseoso(nombre_producto, ctd);
                almacen += gaseoso;
                }
                break;

            case 2:
                {}
                break;

            default:
                continue;
        }

        char s;
        std::cout << "\nPresione S para continuar, N para terminar: ";
        std::cin >> s;
        if(s == 'n' || s == 'N'){
            break;
        }
    }while (true);

    std::cout << "Productos almacenados:" << std::endl;
    auto mostrar_producto = [](CMaterial& material){
        std::cout<< "Producto: " << material.get_nombre() << "  - Cantidad: "<< material.get_cantidad() << " " << material.get_unidad_de_medida();
    };
    almacen.MostrarInventario(mostrar_producto);

    /* Productos liquidos */
    std::cout<< "\n\nProductos Líquidos\n\n";
    almacen.MostrarInventario(mostrar_producto, TTipoMaterial::liquido);
    float volumen_ocupado = almacen.CalcularVolumenTotal();
    std::cout << "Volumen Ocupado: " << volumen_ocupado << std::endl;
	
    return 0;
}

//Modifique el programa anterior para que se ejecute correctamente brindando la posibilidad de incluir Materiales contables y Líquidos.
