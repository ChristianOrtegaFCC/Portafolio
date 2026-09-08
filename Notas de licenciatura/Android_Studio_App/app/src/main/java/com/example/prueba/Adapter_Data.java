package com.example.prueba;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class Adapter_Data extends RecyclerView.Adapter<Adapter_Data.ViewHolderDatos> {
    ArrayList<User_Item> lista;

    public Adapter_Data(ArrayList<User_Item> lista) {
        this.lista = lista;
    }

    @NonNull
    @Override
    public Adapter_Data.ViewHolderDatos onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_lista, null, false);
        return new ViewHolderDatos(v);
    }

    @Override
    public void onBindViewHolder(@NonNull Adapter_Data.ViewHolderDatos holder, int position) {
        holder.asignarDatos(lista.get(position));
    }

    @Override
    public int getItemCount() {
        return lista.size();
    }

    public class ViewHolderDatos extends RecyclerView.ViewHolder {
        TextView idtxt;
        TextView nametxt;
        TextView emailtxt;
        TextView passwdtxt;
        ImageView img;
        public ViewHolderDatos(@NonNull View itemView) {
            super(itemView);
            idtxt = (TextView) itemView.findViewById(R.id.textView5);
            nametxt = (TextView) itemView.findViewById(R.id.textView7);
            emailtxt = (TextView) itemView.findViewById(R.id.textView9);
            passwdtxt = (TextView) itemView.findViewById(R.id.textView12);
            img = (ImageView) itemView.findViewById(R.id.imageView4);
        }

        public void asignarDatos(User_Item Item) {
            idtxt.setText(Item.id.toString());
            nametxt.setText(Item.name.toString());
            emailtxt.setText(Item.email.toString());
            passwdtxt.setText(Item.passwd.toString());

            String idImg = Item.img.toString();

            if (idImg.equals("1.jpg")) {
                img.setImageResource(R.drawable.r1);
            }else if(idImg.equals("2.jpg")){
                img.setImageResource(R.drawable.r2);
            }else if(idImg.equals("3.jpg")){
                img.setImageResource(R.drawable.r3);
            }else if(idImg.equals("4.jpg")){
                img.setImageResource(R.drawable.r4);
            }else{
                img.setImageResource(R.drawable.a1);
            }
        }
    }
}
