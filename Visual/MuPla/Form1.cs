using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using WMPLib;
using System.Diagnostics;

namespace MuPla
{
    public partial class MuPla : Form
    {
        [DllImport("uxtheme", ExactSpelling = true, CharSet = CharSet.Unicode)]
        public extern static Int32 SetWindowTheme(IntPtr hWnd,
              String textSubAppName, String textSubIdList);



        public MuPla()
        {

            InitializeComponent();
            trackBar1.Maximum = 100;
            trackBar1.Value = 100;
            progressbar.Minimum = 0;
            timer1.Start();


            ProgressBar pgs = progressbar;
            pgs.ForeColor = Color.RoyalBlue;
            pgs.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            
            SetWindowTheme(progressbar.Handle, "", "");
        }

        String[] paths, files;
        String[] paths2;

        private bool mouseDown;
        private Point lastLocation;

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            Environment.Exit(1);
        }
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(listBox1.SelectedIndex >= 0 && listBox1.SelectedIndex < paths.Length)
            {
                
                axWindowsMediaPlayer1.URL = paths[listBox1.SelectedIndex];
                //axWindowsMediaPlayer1.Ctlcontrols.currentPosition = 0;
                axWindowsMediaPlayer1.Ctlcontrols.play();
            }
        }

        private void pictureBox3_Click(object sender, EventArgs e) 
        {
            if(axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsPlaying)
            {
                axWindowsMediaPlayer1.Ctlcontrols.pause();
            }

            else if (axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsPaused || axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsStopped)
            {
                axWindowsMediaPlayer1.Ctlcontrols.play();
            }
        }

        private void btnnext_Click(object sender, EventArgs e)
        {
            if(listBox1.SelectedIndex < listBox1.Items.Count-1)
            {
                listBox1.SelectedIndex += 1;
            }

            else if (listBox1.SelectedIndex == listBox1.Items.Count - 1)
            {
                listBox1.SelectedIndex = 0;
            }
        }

        private void btnprev_Click(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex > 0)
            {
                listBox1.SelectedIndex -= 1;
            }

            else if (listBox1.SelectedIndex == 0)
            {
                listBox1.SelectedIndex = listBox1.Items.Count - 1;
            }
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            mouseDown = true;
            lastLocation = e.Location;
        }

        private void panel1_MouseMove(object sender, MouseEventArgs e)
        {
            if (mouseDown)
            {
                this.Location = new Point(
                    (this.Location.X - lastLocation.X) + e.X, (this.Location.Y - lastLocation.Y) + e.Y);

                this.Update();
            }
        }

        private void panel1_MouseUp(object sender, MouseEventArgs e)
        {
            mouseDown = false;
        }

        private void minimize_Click(object sender, EventArgs e)
        {
            this.Hide();
            notifyIcon.Visible = true;
            notifyIcon.ShowBalloonTip(3000, "MuPla is minimized", "Double click icon to open", ToolTipIcon.Info);
        }

        private void notifyIcon1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            this.Show();
            this.WindowState = FormWindowState.Normal;
            notifyIcon.Visible = false;
        }

        private void notifyIcon_BalloonTipClicked(object sender, EventArgs e)
        {
            this.Show();
            this.WindowState = FormWindowState.Normal;
            notifyIcon.Visible = false;
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            axWindowsMediaPlayer1.settings.volume = trackBar1.Value;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsPlaying)
            {
                progressbar.Maximum = (int)axWindowsMediaPlayer1.currentMedia.duration;
                progressbar.Value = (int)axWindowsMediaPlayer1.Ctlcontrols.currentPosition;
                progressbar.Increment(1);
            }
            
        }

        private void checkBox_CheckedChanged(object sender, EventArgs e)
        {
            
        }

        void resetAndPlay()
        {
            axWindowsMediaPlayer1.Ctlcontrols.currentPosition = 0;
            axWindowsMediaPlayer1.Ctlcontrols.play();
        }

        private void axWindowsMediaPlayer1_PlayStateChange(object sender, AxWMPLib._WMPOCXEvents_PlayStateChangeEvent e)
        {
            if (checkBox.Checked == true)
            {
                if (axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsMediaEnded || axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsStopped && listBox1.SelectedIndex >= 0)
                {
                    axWindowsMediaPlayer1.Ctlcontrols.currentPosition = 0;
                    axWindowsMediaPlayer1.Ctlcontrols.play();
                }
            }
            else
            {
                if (axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsMediaEnded || axWindowsMediaPlayer1.playState == WMPLib.WMPPlayState.wmppsStopped && listBox1.SelectedIndex >= 0)
                {
                    if (listBox1.Items.Count > 1)
                    {
                        if (listBox1.SelectedIndex == listBox1.Items.Count - 1)
                        {
                            listBox1.SelectedIndex = listBox1.TopIndex;
                            this.BeginInvoke(new Action(() => {
                                axWindowsMediaPlayer1.URL = paths[listBox1.SelectedIndex];
                            }));
                        }
                        else
                        {
                            listBox1.SelectedIndex++;
                            this.BeginInvoke(new Action(() => {
                                axWindowsMediaPlayer1.URL = paths[listBox1.SelectedIndex];
                            }));
                        }
                    }

                    else
                    {
                        axWindowsMediaPlayer1.Ctlcontrols.play();
                    }
                }
            }
        }

        private void progressbar_Click(object sender, EventArgs e)
        {
            // Get mouse position(x) minus the width of the progressbar (so beginning of the progressbar is mousepos = 0 //
            float absoluteMouse = (PointToClient(MousePosition).X - progressbar.Bounds.X);
            // Calculate the factor for converting the position (progbarWidth/100) //
            float calcFactor = progressbar.Width / (float)progressbar.Maximum;
            // In the end convert the absolute mouse value to a relative mouse value by dividing the absolute mouse by the calcfactor //
            float relativeMouse = absoluteMouse / calcFactor;

            // Set the calculated relative value to the progressbar //
            //progressbar.Value = Convert.ToInt32(relativeMouse);
            axWindowsMediaPlayer1.Ctlcontrols.currentPosition = Convert.ToInt32(relativeMouse);

            if(listBox1.SelectedIndex >= 0)
            {
                axWindowsMediaPlayer1.Ctlcontrols.play();
            }
        }

        private void btnImport_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();

            ofd.Multiselect = true;

            ofd.Filter = "All Supported Audio | *.mp3; *.wma | MP3s | *.mp3 | WMAs | *.wma";

            if (ofd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                files = ofd.SafeFileNames;

                if (paths != null)
                {
                    int len = paths.Length;
                    paths2 = ofd.FileNames;
                    Array.Resize(ref paths, len + paths2.Length);
                    paths2.CopyTo(paths, len);
                }

                else
                {

                    paths = ofd.FileNames;
                }

                for (int i = 0; i <  files.Length; i++)
                {
                    listBox1.Items.Add(files[i]);
                }
            }
        }
    }
}
