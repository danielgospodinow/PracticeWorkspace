package com.example.dgospodinow.danchosclient;

import java.net.*;
import java.io.*;
import java.util.Enumeration;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;


public class Client extends Activity
{
    private TextView text;
    private Socket socket;
    private EditText editText;
    private Button button;
    private Button sendButton;
    private EditText messageBox;
    private TextView chatBox;
    private Thread clientThread;
    private String HostIP;
    private final int SERVERORT = 8081;
    private DataInputStream dataInputStream;
    private DataOutputStream dataOutputStream;
    private boolean socketConnected;

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        socketConnected = false;

        text = (TextView) findViewById(R.id.textmain);
        text.setText("Client");

        editText = (EditText) findViewById(R.id.editText);

        messageBox = (EditText) findViewById(R.id.editText2);

        chatBox = (TextView) findViewById(R.id.textView);

        button = (Button) findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if((clientThread != null && clientThread.isAlive()) ||
                        editText.getText().toString() == "" ||
                        socketConnected)
                    return;

                HostIP = editText.getText().toString();

                clientThread = new Thread(new ClientThread(HostIP));
                clientThread.start();
            }
        });

        sendButton = (Button) findViewById(R.id.button2);
        sendButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (socketConnected == false || dataOutputStream == null)
                    return;

                chatBox.setText(chatBox.getText() + "\nYou: " + messageBox.getText());

                try {
                    dataOutputStream.writeUTF(messageBox.getText().toString());
                    dataOutputStream.flush();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    class ClientThread implements Runnable
    {
        private String hostIP;

        public ClientThread(String IPAdress)
        {
                this.hostIP = IPAdress;
        }

        public void run()
        {
            try {
                socket = new Socket(this.hostIP, SERVERORT);
                socketConnected = true;
                dataInputStream = new DataInputStream(socket.getInputStream());
                dataOutputStream = new DataOutputStream(socket.getOutputStream());
            } catch (IOException e) {
                e.printStackTrace();
            }

            while(true)
            {
               //Exchange Data
                try {
                    if(dataInputStream.available() == 0)
                        return;

                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                chatBox.setText(chatBox.getText().toString() + "\n" + dataInputStream.readUTF());
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                        }
                    });
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
