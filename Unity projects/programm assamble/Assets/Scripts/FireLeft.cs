using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireLeft : MonoBehaviour
{

    SpriteRenderer sr;
    // Use this for initialization
    void Start()
    {
        sr = GetComponent<SpriteRenderer>();
        sr.enabled = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetAxis("Rotate") > 0)
        {
            sr.enabled = true;
        }
        else
        {
            sr.enabled = false;
        }

    }
}