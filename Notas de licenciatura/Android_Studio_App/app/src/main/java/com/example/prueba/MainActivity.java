package com.example.prueba;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
    ConexionSqlHelper conn;
    SQLiteDatabase db;
    EditText user_main;
    EditText password_main;
    Button btn1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btn1 = (Button) findViewById(R.id.button_sign_in);
        btn1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                btn1OnClick(view);
            }
        });
    }

    public void btn1OnClick(View v){
        user_main = (EditText) findViewById(R.id.user_main);
        password_main = (EditText) findViewById(R.id.passwd_main);
        String[] user = {user_main.getText().toString()};
        String passwd = password_main.getText().toString();

        if(!user[0].equals("") && !passwd.equals("")){
            conn = new ConexionSqlHelper(this, "buap", null, 1);
            db = conn.getReadableDatabase();

            String sql = "SELECT * FROM user WHERE email = ?";
            Cursor cursor = db.rawQuery(sql, user);

            String id="", name="", email="", pass="";
            while(cursor.moveToNext()){
                id = cursor.getInt(0) +"";
                name = cursor.getString(1);
                email = cursor.getString(2);
                pass = cursor.getString(3);
                //System.out.println("id: "+id+"\n name: "+name+"\n email: "+email+"\n password: "+pass);
            }

            if(user[0].equals(email) && passwd.equals(pass)){
                Intent i = new Intent(this, MenuActivity.class);
                i.putExtra("email", email);
                i.putExtra("name", name);
                startActivity(i);
            }else{
                alert("The username or password is incorrect", "Error");
            }
            cursor.close();
            db.close();
        }else{
            alert("Insert username and password", "Error");
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