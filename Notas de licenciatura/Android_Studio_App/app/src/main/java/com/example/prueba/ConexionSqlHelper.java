package com.example.prueba;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class ConexionSqlHelper extends SQLiteOpenHelper {

    String TableUser = "CREATE TABLE user( id INT PRIMARY KEY NOT NULL, name TEXT, email TEXT, password TEXT, img TEXT)";
    String AddUser_root = "INSERT INTO user VALUES (1, 'root', 'root@root.com', 'toor', '1.jpg')";
    public ConexionSqlHelper(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL(TableUser);
        sqLiteDatabase.execSQL(AddUser_root);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        sqLiteDatabase.execSQL("DROP TABLE IF EXISTS user");
        onCreate(sqLiteDatabase);
    }
}
