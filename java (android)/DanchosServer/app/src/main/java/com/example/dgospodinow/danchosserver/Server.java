package com.example.dgospodinow.danchosserver;

import java.io.*;
import java.net.*;
import java.util.Enumeration;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class Server extends Activity {

    private ServerSocket serverSocket;
    private Socket socket;
    private boolean socketConnected;
    private DataOutputStream dataOutputStream;
    private DataInputStream dataInputStream;
    private TextView text;
    private EditText messageBox;
    private TextView chatBox;
    private Button sendButton;
    public static final int SERVERPORT = 8081;

    @Override
    public void onCreate(Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        text = (TextView) findViewById(R.id.textView);
        text.setText("Server");

        String allIP = GetIPAdresses();
        text.setText(allIP);

        messageBox = (EditText) findViewById(R.id.textView3);

        chatBox = (TextView) findViewById(R.id.textView2);

        sendButton = (Button) findViewById(R.id.button2);
        sendButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (socketConnected == false)
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

        Thread serverThread = new Thread(new ServerThread());
        serverThread.start();
    }

    class ServerThread implements Runnable
    {
        public void run()
        {
            socket = null;

            try
            {
                serverSocket = new ServerSocket(SERVERPORT);
                socket = serverSocket.accept();
                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {text.setText("Successful connection!");}
                });
                socketConnected = true;
                dataOutputStream = new DataOutputStream(socket.getOutputStream());
                dataInputStream = new DataInputStream(socket.getInputStream());
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }

            while(socketConnected)
            {
                //Exchange Data
                try {
                    if(dataInputStream.readUTF() == "")
                        return;


                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            try {
                                chatBox.setText(chatBox.getText().toString() + "\n" + "Friend: " + dataInputStream.readUTF());
                                dataInputStream.reset();
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

    private String GetIPAdresses()
    {
        String allIPAdresses = "";

        Enumeration e = null;
        try
        {
            e = NetworkInterface.getNetworkInterfaces();
        }
        catch (SocketException e1)
        {
            e1.printStackTrace();
        }

        if(e != null) {
            while (e.hasMoreElements()) {
                NetworkInterface n = (NetworkInterface) e.nextElement();
                Enumeration ee = n.getInetAddresses();
                while (ee.hasMoreElements()) {
                    InetAddress i = (InetAddress) ee.nextElement();
                    System.out.println(i.getHostAddress());
                    //text.setText(text.getText() + "\n" + i.getHostAddress());
                    allIPAdresses += (i.getHostAddress() + "\n");
                }
            }
        }

        return allIPAdresses;
    }

    @Override
    protected void onStop()
    {
        super.onStop();
        CloseCurrentSocket();
    }

    public void CloseCurrentSocket()
    {
        socketConnected = false;
        try
        {
            serverSocket.close();
        } catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}