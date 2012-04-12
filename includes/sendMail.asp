<%@Language=VbScript%>
<%
	Response.Expires=0
	dim msg : msg=""
	msg = "Fomulaire envoyé le : " & now() & VbCrlf
	msg = msg & "Adresse IP : " & Request.ServerVariables("REMOTE_ADDR") & VbCrlf
	msg = msg & "---------------------------------------" & VbCrlf
	msg = msg & "Nom : " & request.Form("nom") & VbCrlf
	msg = msg & "Courriel : " & request.Form("courriel") & VbCrlf
	msg = msg & "Téléphone : " & request.Form("telephone") & VbCrlf
	msg = msg & "Message : " & request.Form("message") & VbCrlf
	msg = msg & "---------------------------------------" & VbCrlf
	
	Set objMailer = Server.CreateObject("Dundas.Mailer")
	objMailer.BodyCharSet="iso-8859-1"
	objMailer.SMTPRelayServers.add "smtp.live.com"
	objMailer.FromAddress=request.Form("courriel")
	objMailer.Subject="Demande d'information" 	
	objMailer.TOs.Add "lessentinelles@hotmail.com" 
	objMailer.Body=msg
		
	'We need to catch the error.
    On Error Resume Next
    objMailer.SendMail
    If (Err <> 0) Then
    	Response.Write "There was an error sending the email: " & Err.Description
    End If
	
	set objMailer=nothing

	response.Redirect "merci.html"
	
	
%>