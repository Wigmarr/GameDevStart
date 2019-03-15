using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MainFire : MonoBehaviour {

    SpriteRenderer sr;
	// Use this for initialization
	void Start () {
        sr = GetComponent<SpriteRenderer>();
        sr.enabled = false;
    }
	
	// Update is called once per frame
	void Update () {
		if (Input.GetAxis("Thrust") != 0)
        {
            sr.enabled = true;
        } else
        {
            sr.enabled = false;
        }

	}
}
