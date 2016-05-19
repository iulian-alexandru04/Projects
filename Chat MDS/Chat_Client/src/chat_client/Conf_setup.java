/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * Conf_setup.java
 *
 * Created on May 31, 2010, 1:16:53 PM
 */

package chat_client;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import javax.swing.DefaultListModel;
import javax.swing.JLabel;

/**
 *
 * @author Daniel
 */
public class Conf_setup extends javax.swing.JFrame {
public static DefaultListModel model1,model2;
public static int n1,n2=0;
public static Socket s;
public static DataOutputStream stream;
    /** Creates new form Conf_setup */
    public Conf_setup() {
        s=Meniu.s;
        initComponents();
        model1 = new DefaultListModel();
        lista1.setCellRenderer(new LabelListCellRenderer());
        //model1=Meniu.model;
        lista1.setModel(model1);
        n1=Meniu.n;
        for(int i=0;i<n1;i++)
        {
            model1.addElement((JLabel)Meniu.model.getElementAt(i));
        }
        model2 = new DefaultListModel();
        lista2.setCellRenderer(new LabelListCellRenderer());
        lista2.setModel(model2);
    }
    public void adauga(int i)
    {
        if (i<0) i=0;
        if (n1>=1)
        {
        JLabel j=new JLabel();
        j=(JLabel)model1.getElementAt(i);
        model2.addElement(j);
        model1.remove(i);
        n1--;
        n2++;
        }
    }
    public void sterge(int i)
    {
        if (i<0) i=0;
        if (n2>=1)
        {
        model1.addElement((JLabel)model2.getElementAt(i));
        n1++;
        model2.remove(i);
        n2--;
        }
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        lista2 = new javax.swing.JList();
        jScrollPane2 = new javax.swing.JScrollPane();
        lista1 = new javax.swing.JList();
        add = new javax.swing.JButton();
        remove = new javax.swing.JButton();
        invita = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setResizable(false);

        lista2.setModel(new javax.swing.AbstractListModel() {
            String[] strings = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
            public int getSize() { return strings.length; }
            public Object getElementAt(int i) { return strings[i]; }
        });
        jScrollPane1.setViewportView(lista2);

        lista1.setModel(new javax.swing.AbstractListModel() {
            String[] strings = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
            public int getSize() { return strings.length; }
            public Object getElementAt(int i) { return strings[i]; }
        });
        jScrollPane2.setViewportView(lista1);

        add.setText("add->");
        add.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                addActionPerformed(evt);
            }
        });

        remove.setText("<-remove");
        remove.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                removeActionPerformed(evt);
            }
        });

        invita.setText("invita");
        invita.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                invitaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGap(26, 26, 26)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 116, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(invita, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 94, Short.MAX_VALUE)
                    .addComponent(remove, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 94, Short.MAX_VALUE)
                    .addComponent(add, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, 94, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 117, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(35, 35, 35))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(90, 90, 90)
                .addComponent(add)
                .addGap(44, 44, 44)
                .addComponent(remove)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 78, Short.MAX_VALUE)
                .addComponent(invita, javax.swing.GroupLayout.PREFERRED_SIZE, 31, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
            .addGroup(layout.createSequentialGroup()
                .addGap(40, 40, 40)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 199, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap())
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 199, Short.MAX_VALUE)
                        .addContainerGap(61, Short.MAX_VALUE))))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void addActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_addActionPerformed
       adauga(lista1.getSelectedIndex());
    }//GEN-LAST:event_addActionPerformed

    private void removeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_removeActionPerformed
        sterge(lista2.getSelectedIndex());
    }//GEN-LAST:event_removeActionPerformed

    private void invitaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_invitaActionPerformed

        String s_conf="";
        for(int i=0;i<n2;i++)
        {
        JLabel j=new JLabel();
        j=(JLabel)model2.getElementAt(i);
        s_conf+=j.getText()+" ";
        }
        try {
            stream = new DataOutputStream(s.getOutputStream());
        } catch (IOException ex) {
            System.out.println("Streamul nu poate fi creat");
        }
        try {
            stream.writeUTF("/conf "+s_conf);
            System.out.println("/conf "+s_conf);
        } catch (IOException ex) {
            System.out.println("textul nu poate fi scris");
            return;
        }
        if (Meniu.conf == null )
                    {
                        Meniu.conf = new Conferinta(s_conf);
                        Meniu.conf.setVisible(true);
                    }
        this.dispose();
    }//GEN-LAST:event_invitaActionPerformed

    /**
    * @param args the command line arguments
    */
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Conf_setup().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton add;
    private javax.swing.JButton invita;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JList lista1;
    private javax.swing.JList lista2;
    private javax.swing.JButton remove;
    // End of variables declaration//GEN-END:variables

}