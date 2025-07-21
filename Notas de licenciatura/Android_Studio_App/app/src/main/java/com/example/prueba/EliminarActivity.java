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

public class EliminarActivity extends AppCompatActivity {

    ConexionSqlHelper conn;
    SQLiteDatabase db;
    ConstraintLayout back;
    Button find_id, delete, cancel;
    EditText id, name, email;
    Spinner img;
    String selector;
    String [] _id = {""};
    ArrayList<String> obj;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_eliminar);

        back = (ConstraintLayout) findViewById(R.id.btn_back_show);
        find_id = (Button) findViewById(R.id.btn_id_find_del);
        id = (EditText) findViewById(R.id.id_del);
        name = (EditText) findViewById(R.id.name_del);
        email = (EditText) findViewById(R.id.email_del);
        img = (Spinner) findViewById(R.id.spiner_del);
        delete = (Button) findViewById(R.id.btn_delete_del);
        cancel = (Button) findViewById(R.id.btn_cancel_show);

        obj = new ArrayList<String>();

        obj.add("1.jpg");
        obj.add("2.jpg");
        obj.add("3.jpg");
        obj.add("4.jpg");
        obj.add("5.jpg");

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

        delete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                ClickDelete(view);
            }
        });

        cancel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });

    }

    public Boolean ClickFind(View v){
        Boolean aux = false;
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
                    aux = true;
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
        return aux;
    }

    public void ClickDelete(View v){
        String[] params = {""};

        if(ClickFind(v) == true) {
            params[0] = id.getText().toString();
            _delete(params);
        }
    }

    public void _delete(String[] params){
        conn = new ConexionSqlHelper(this, "buap", null, 1);
        db = conn.getReadableDatabase();

        try {
            String sql = "DELETE FROM user WHERE id = ?";
            db.execSQL(sql, params);
            id.setText("");
            name.setText("");
            email.setText("");
            img.setSelection(0);
            alert("User deleted successfully", "Success");
        } catch (Exception ex) {
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