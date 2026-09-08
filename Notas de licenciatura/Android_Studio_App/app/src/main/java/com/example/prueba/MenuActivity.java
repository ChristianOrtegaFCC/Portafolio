package com.example.prueba;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MenuActivity extends AppCompatActivity {

    TextView show_name, show_email;
    ConstraintLayout btnAdd, btnBack, btnMod, btnDel, btnShow;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_menu);

        show_name = (TextView) findViewById(R.id.show_name_menu);
        show_email = (TextView) findViewById(R.id.show_email_menu);

        Intent i = getIntent();
        show_name.setText(i.getStringExtra("name"));
        show_email.setText(i.getStringExtra("email"));

        btnBack = (ConstraintLayout) findViewById(R.id.btnBack_Menu);
        btnAdd = (ConstraintLayout) findViewById(R.id.btn_Add_menu);
        btnMod = (ConstraintLayout) findViewById(R.id.btn_modify_menu);
        btnDel = (ConstraintLayout) findViewById(R.id.btnDel_menu);
        btnShow = (ConstraintLayout) findViewById(R.id.btn_show_menu);

        btnAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                OnClickAdd(view);
            }
        });

        btnMod.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                OnClickModify(view);
            }
        });

        btnDel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                OnClickDelete(view);
            }
        });

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //finish();
                Intent i = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(i);
            }
        });

        btnShow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                OnClickShow(view);
                //finish();
                //Intent i = new Intent(getApplicationContext(), MainActivity.class);
                //startActivity(i);
            }
        });
    }

    public void OnClickAdd(View v){
        Intent i = new Intent(this, AgregarActivity.class);
        startActivity(i);
    }

    public void OnClickModify(View v){
        Intent i = new Intent(this, ModificarActivity.class);
        startActivity(i);
    }

    public void OnClickDelete(View v){
        Intent i = new Intent(this, EliminarActivity.class);
        startActivity(i);
    }

    public void OnClickShow(View v){
        Intent i = new Intent(this, MostrarActivity.class);
        startActivity(i);
    }
}