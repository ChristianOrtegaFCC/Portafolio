package com.example.prueba;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;

import java.util.ArrayList;

public class AgregarActivity extends AppCompatActivity {
    ConstraintLayout btnBack;
    EditText name_add, email_add, passwd_add, conf_passwd_add;
    Spinner spinner_add;
    Button btn_add, btn_cancel;
    String selector;
    ConexionSqlHelper conn;
    SQLiteDatabase db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_agregar);
        btnBack = (ConstraintLayout) findViewById(R.id.btnBack_add);
        name_add = (EditText) findViewById(R.id.name_add);
        email_add = (EditText) findViewById(R.id.Email_add);
        spinner_add = (Spinner) findViewById(R.id.spinner_add);
        passwd_add = (EditText) findViewById(R.id.passwd_add);
        conf_passwd_add = (EditText) findViewById(R.id.conf_passwd_add);
        btn_add = (Button) findViewById(R.id.button_add);
        btn_cancel = (Button) findViewById(R.id.button_cancel_add);
        ArrayList<String> obj = new ArrayList<String>();

        obj.add("1.jpg");
        obj.add("2.jpg");
        obj.add("3.jpg");
        obj.add("4.jpg");

        ArrayAdapter<CharSequence> adapter = new ArrayAdapter(this, android.R.layout.simple_spinner_item, obj);
        spinner_add.setAdapter(adapter);

        spinner_add.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                selector = adapterView.getItemAtPosition(i).toString();
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

        btn_add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btn_click_add(view);
            }
        });

        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view){
                //finish();
                Intent i = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(i);
            }
        });

        btn_cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });
    }

    public void btn_click_add(View v){
        String error = "";

        if(name_add.getText().toString().equals("")){
            error += "Missing Name\n";
        }
        if(email_add.getText().toString().equals("")){
            error += "Missing Email\n";
        }
        if(passwd_add.getText().toString().equals("")){
            error += "Missing Password\n";
        }
        if(conf_passwd_add.getText().toString().equals("")){
            error += "Missing Password Confirm\n";
        }else if(!passwd_add.getText().toString().equals("") && !conf_passwd_add.getText().toString().equals(passwd_add.getText().toString())){
            error += "Password do not match\n";
        }

        if(error.equals("")){
            insert_user(getMax_id_User(), name_add.getText().toString(), email_add.getText().toString(), passwd_add.getText().toString(), selector);
        }else{
            alert(error, "error");
        }
    }

    public void mostrar(){
        conn = new ConexionSqlHelper(this, "buap", null, 1);
        db = conn.getReadableDatabase();

        try {
            String sql = "SELECT * FROM user";
            Cursor cursor = db.rawQuery(sql, null);

            while(cursor.moveToNext()){
                System.out.println("ID: "+cursor.getInt(0));
                System.out.println("NAME: "+cursor.getString(1));
            }
        }catch (Exception ex){
            alert(ex.getMessage().toString(), "Database failed");
        }

        conn.close();
        db.close();
    }

    public String getMax_id_User(){
        conn = new ConexionSqlHelper(this, "buap", null, 1);
        db = conn.getReadableDatabase();
        int max = 0;

        try {
            String sql = "SELECT MAX(id) AS id FROM user";
            Cursor cursor = db.rawQuery(sql, null);

            while(cursor.moveToNext()){
                max = cursor.getInt(0);
            }
            max++;
        }catch (Exception ex){
            alert(ex.getMessage().toString(), "Database failed");
        }

        conn.close();
        db.close();

        return max+"";
    }

    public void insert_user(String id, String name, String email, String password, String img){
        conn = new ConexionSqlHelper(this, "buap", null, 1);
        db = conn.getReadableDatabase();

        try{
            String sql = "INSERT INTO user VALUES(?, ?, ?, ?, ?);";
            String[] params = {id, name, email, password, img};

            db.execSQL(sql, params);
            name_add.setText("");
            email_add.setText("");
            spinner_add.setSelection(0);
            passwd_add.setText("");
            conf_passwd_add.setText("");
            alert("User added successfully", "Success");
        }catch (Exception ex){
            alert(ex.getMessage().toString(), "Database failed");
        }
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