// Set the precision we need when using GL_ES
#ifdef GL_ES
precision lowp float;
#endif

// Color sent in from the vertex shader
varying     vec4        varInColor;
// Texture coordinate from the vertex shader
varying     vec2        varTexCoord;

// Texture to be sampled
uniform     sampler2D   texture;
uniform     int         u_opacityModifyRGB;

vec4 color;

void main()
{
    if (u_opacityModifyRGB == 1) {
        color = vec4(varInColor.r * varInColor.a,
                     varInColor.g * varInColor.a,
                     varInColor.b * varInColor.a,
                     varInColor.a);
    } else {
        color = varInColor;
    }
    
    //gl_FragColor =  color * texture2D(uniTexture, varTexCoord);
    vec4 mainImage =  texture2D(texture, varTexCoord);
    gl_FragColor = vec4(mainImage.xyz,mainImage.w) ;
    
    //gl_FragColor =  vec4(varTexCoord.xy,0.0,1.0);
    
    //gl_FragColor =  vec4(1.0,1.0,0.0,1.0);
}