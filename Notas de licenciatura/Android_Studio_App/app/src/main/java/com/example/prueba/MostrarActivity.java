package com.example.prueba;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import java.util.ArrayList;

public class MostrarActivity extends AppCompatActivity {
    ArrayList<User_Item> lista;
    ConexionSqlHelper conn;
    SQLiteDatabase db;
    RecyclerView recyclerView;
    ConstraintLayout btnBack;
    Button btnCancel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_mostrar);

        btnBack = (ConstraintLayout) findViewById(R.id.btn_back_show);
        btnCancel = (Button) findViewById(R.id.btn_cancel_show);
        recyclerView = (RecyclerView) findViewById(R.id.recyclerView);
        //recyclerView.setLayoutManager(new LinearLayoutManager(this, LinearLayoutManager.VERTICAL,
        //        false));
        recyclerView.setLayoutManager(new GridLayoutManager(this, 1));

        lista = new ArrayList<User_Item>();
        mostrar();
        Adapter_Data adapter = new Adapter_Data(lista);
        recyclerView.setAdapter(adapter);

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //finish();
                Intent i = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(i);
            }
        });

        btnCancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
                //Intent i = new Intent(getApplicationContext(), MainActivity.class);
                //startActivity(i);
            }
        });
    }

    public void mostrar(){
        conn = new ConexionSqlHelper(this, "buap", null, 1);
        db = conn.getReadableDatabase();

        try {
            String sql = "SELECT * FROM user";
            Cursor cursor = db.rawQuery(sql, null);

            while(cursor.moveToNext()){
                User_Item u = new User_Item(cursor.getString(0), cursor.getString(1), cursor.getString(2),
                                        cursor.getString(3), cursor.getString(4));
                lista.add(u);
                //System.out.println("ID: "+cursor.getInt(0));
                //System.out.println("NAME: "+cursor.getString(1));
            }
        }catch (Exception ex){
            alert(ex.getMessage().toString(), "Database failed");
        }

        conn.close();
        db.close();
    }

    public void alert(String line, String tittle){
        AlertDialog.Builder message = new AlertDialog.Builder(this);
        message.setTitle(tittle)
                .setMessage(line)
                .setCancelable(true)
                .setPositiveButton("OK", new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        //
                    }
                }).show();
    }
}