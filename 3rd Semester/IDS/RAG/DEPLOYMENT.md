# Deployment Guide for Hugging Face Spaces

## Prerequisites

1. Hugging Face account (create one at https://huggingface.co/)
2. Groq API key (get one at https://console.groq.com/)

## Steps to Deploy

### 1. Create a New Space

1. Go to https://huggingface.co/spaces
2. Click "Create new Space"
3. Fill in the details:
   - **Space name**: Your chosen name (e.g., `rag-pdf-chatbot`)
   - **SDK**: Select "Gradio"
   - **Hardware**: CPU Basic (free tier is sufficient)
   - **Visibility**: Public or Private (your choice)
4. Click "Create Space"

### 2. Upload Files

Upload the following files to your Space repository:

- `app.py` - Main application file
- `requirements.txt` - Python dependencies
- `README.md` - Documentation
- `DEPLOYMENT.md` - This file (optional)

### 3. Set Up Secrets

1. In your Space, go to "Settings" tab
2. Navigate to "Repository secrets" section
3. Add a new secret:
   - **Name**: `GROQ_API_KEY`
   - **Value**: Your Groq API key
4. Click "Save secret"

### 4. Wait for Deployment

- Hugging Face will automatically detect your `app.py` and start building
- The build process will:
  - Install dependencies from `requirements.txt`
  - Download the sentence transformer model
  - Start the Gradio app
- This may take 5-10 minutes on first deployment

### 5. Access Your App

Once deployment is complete, you can access your app at:
```
https://huggingface.co/spaces/YOUR_USERNAME/YOUR_SPACE_NAME
```

## Troubleshooting

### Build Fails

- Check that `requirements.txt` has all necessary packages
- Verify Python version compatibility (Gradio spaces use Python 3.9+)
- Check build logs in the "Logs" tab

### API Key Issues

- Ensure `GROQ_API_KEY` is set correctly in Repository secrets
- Verify the key is valid at https://console.groq.com/
- Check that the secret name matches exactly: `GROQ_API_KEY`

### Model Loading Takes Too Long

- First deployment downloads the sentence transformer model (~90MB)
- Subsequent deployments use cached models
- Consider using a smaller model if speed is an issue

### Memory Issues

- If you get out-of-memory errors, try:
  - Using smaller PDF files
  - Reducing chunk size in `app.py`
  - Reducing `top_k` in retrieval

## Updating Your Space

To update your deployed app:

1. Push changes to your Space repository (via Git or web interface)
2. Hugging Face will automatically rebuild and redeploy
3. Changes typically take 2-5 minutes to go live

## Custom Domain (Optional)

You can add a custom domain in Space Settings > Domain.

## Monitoring

- View app logs in the "Logs" tab
- Check resource usage in the "Metrics" tab
- Monitor API usage in Groq dashboard


