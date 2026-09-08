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

public class ModificarActivity extends AppCompatActivity {

    ConexionSqlHelper conn;
    SQLiteDatabase db;
    ConstraintLayout back;
    Button find_id, modify, cancel;
    EditText id, name, email, password, conf_passwd;
    Spinner img;
    String selector;
    String [] _id = {""};
    ArrayList<String> obj;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_modificar);

        back = (ConstraintLayout) findViewById(R.id.btn_back_modify);
        find_id = (Button) findViewById(R.id.btn_id_find);
        id = (EditText) findViewById(R.id.id_modify);
        name = (EditText) findViewById(R.id.name_modify);
        email = (EditText) findViewById(R.id.email_modify);
        img = (Spinner) findViewById(R.id.spiner_modify);
        password = (EditText) findViewById(R.id.passwd_modify);
        conf_passwd = (EditText) findViewById(R.id.conf_passwd_modify);
        modify = (Button) findViewById(R.id.btn_modify_modify);
        cancel = (Button) findViewById(R.id.btn_cancel_modify);

        obj = new ArrayList<String>();

        obj.add("1.jpg");
        obj.add("2.jpg");
        obj.add("3.jpg");
        obj.add("4.jpg");

        ArrayAdapter<CharSequence> adapter = new ArrayAdapter(this, android.R.layout.simple_spinner_item, obj);
        img.setAdapter(adapter);

        img.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int i, long l) {
                selector = adapterView.getItemAtPosition(i).toString();
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {

            }
        });

        back.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent i = new Intent(getApplicationContext(), MainActivity.class);
                startActivity(i);
            }
        });

        find_id.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ClickFind(view);
            }
        });

        modify.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ClickModify(view);
            }
        });

        cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });
    }

    public void ClickFind(View v){
        conn = new ConexionSqlHelper(this, "buap", null, 1);
        db = conn.getReadableDatabase();

        if(!id.getText().toString().equals("")) {
            _id[0] = id.getText().toString();
            String[] param = {_id[0]};

            try {
                String sql = "SELECT * FROM user WHERE id = ?";
                Cursor cursor = db.rawQuery(sql, param);
                if (cursor.getCount() > 0) {
                    while (cursor.moveToNext()) {
                        name.setText(cursor.getString(1));
                        email.setText(cursor.getString(2));
                        img.setSelection(obj.indexOf(cursor.getString(4)));
                    }
                } else {
                    alert("The ID: "+_id[0]+" doesn't exist", "ERROR!!!...");
                }
            } catch (Exception ex) {
                alert(ex.getMessage().toString(), "Database failed");
            }
        }else{
            alert("Enter the ID", "ERROR!!!...");
        }

        conn.close();
        db.close();
    }

    public void ClickModify(View v){
        int conf = 0;
        String[] params = new String[6];
        EditText[] data = {id, name, email, password, conf_passwd};
        String error = "";

        for (int i = 0; i < 4; i++) {
            if(data[i].getText().toString().equals("")){
                error += "Missing "+data[i].getHint()+"\n";
            }else{
                params[i] = data[i].getText().toString();
            }
        }

        if(data[4].getText().toString().equals("")){
            error += "Missing Password Confirm\n";
        }else if(!data[3].getText().toString().equals("") && !data[4].getText().toString().equals(data[3].getText().toString())){
            error += "Password do not match\n";
        }
        
        if(error.equals("")){
            if(!_id[0].equals(data[0].getText().toString())){
                String [] aux = {data[0].getText().toString()};
                conf = search_id(aux);
            }

            if(conf == 0) {
                params[4] = selector;
                params[5] = _id[0];
                _modify(params);
            }else if(conf == 1) {
                alert("The item is already registered.", "ERROR!!!...");
            }
        }else{
            alert(error, "ERROR!!!...");
        }
    }

    public void _modify(String[] params){
        conn = new ConexionSqlHelper(this, "buap", null, 1);
        db = conn.getReadableDatabase();

        try {
            String sql = "UPDATE user SET id=?, name=?, email=?, password=?, img=? WHERE id = ?";
            db.execSQL(sql, params);
            id.setText("");
            name.setText("");
            email.setText("");
            img.setSelection(0);
            password.setText("");
            conf_passwd.setText("");
            alert("User modified successfully", "Success");
        } catch (Exception ex) {
            alert(ex.getMessage().toString(), "Database failed");
        }
        conn.close();
        db.close();
    }

    public int search_id(String [] id){
        int aux = 0;
        conn = new ConexionSqlHelper(this, "buap", null, 1);
        db = conn.getReadableDatabase();

        try {
            String sql = "SELECT * FROM user WHERE id = ?";
            Cursor cursor = db.rawQuery(sql, id);
            if (cursor.getCount() > 0) {
                conn.close();
                db.close();
                aux = 1;
            } else {
                conn.close();
                db.close();
            }
        } catch (Exception ex) {
            conn.close();
            db.close();
            alert(ex.getMessage().toString(), "Database failed");
            aux = 2;
        }
        return aux;
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