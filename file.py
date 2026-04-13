import yt_dlp
import os

# Your playlist URL
playlist_url = "https://youtube.com/playlist?list=PLKnIA16_RmvYuZauWaPlRTC54KxSNLtNn"

# Folder to save videos
download_path = "lectures_61_to_84"
os.makedirs(download_path, exist_ok=True)

# yt-dlp options
ydl_opts = {
    'format': 'bestvideo+bestaudio/best',
    'outtmpl': os.path.join(download_path, '%(playlist_index)s - %(title)s.%(ext)s'),

    # 🔥 THIS IS IMPORTANT PART
    'playliststart': 61,
    'playlistend': 84,
}

with yt_dlp.YoutubeDL(ydl_opts) as ydl:
    ydl.download([playlist_url])

print("✅ Download complete!")
